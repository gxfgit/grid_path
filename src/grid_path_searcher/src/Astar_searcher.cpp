#include "Astar_searcher.h"

using namespace std;
using namespace Eigen;

void AstarPathFinder::initGridMap(double _resolution, Vector3d global_xyz_l, Vector3d global_xyz_u, int max_x_id, int max_y_id, int max_z_id)
{   
    //the edge 
    gl_xl = global_xyz_l(0);
    gl_yl = global_xyz_l(1);
    gl_zl = global_xyz_l(2);

    gl_xu = global_xyz_u(0);
    gl_yu = global_xyz_u(1);
    gl_zu = global_xyz_u(2);
    //number of rect in xyz direction
    GLX_SIZE = max_x_id;
    GLY_SIZE = max_y_id;
    GLZ_SIZE = max_z_id;
    GLYZ_SIZE  = GLY_SIZE * GLZ_SIZE;
    GLXYZ_SIZE = GLX_SIZE * GLYZ_SIZE;// the total number of rect 

    resolution = _resolution;
    inv_resolution = 1.0 / _resolution;    

    data = new uint8_t[GLXYZ_SIZE];
    memset(data, 0, GLXYZ_SIZE * sizeof(uint8_t));
    
    GridNodeMap = new GridNodePtr ** [GLX_SIZE];
    for(int i = 0; i < GLX_SIZE; i++){
        GridNodeMap[i] = new GridNodePtr * [GLY_SIZE];
        for(int j = 0; j < GLY_SIZE; j++){
            GridNodeMap[i][j] = new GridNodePtr [GLZ_SIZE];
            int k =0;
            Vector3i tmpIdx(i,j,k);
            Vector3d pos = gridIndex2coord(tmpIdx);// contain the coord information of each rect
            GridNodeMap[i][j][k] = new GridNode(tmpIdx, pos);
        }
    }
}

void AstarPathFinder::resetGrid(GridNodePtr ptr)
{
    ptr->id = 0;
    ptr->cameFrom = NULL;
    ptr->gScore = inf;
    ptr->fScore = inf;
}

void AstarPathFinder::resetUsedGrids()
{   
    for(int i=0; i < GLX_SIZE ; i++)
        for(int j=0; j < GLY_SIZE ; j++)
                resetGrid(GridNodeMap[i][j][0]);
}


vector<Vector3d> AstarPathFinder::getVisitedNodes()
{   
    vector<Vector3d> visited_nodes;
    int k = 0;
    for(int i = 0; i < GLX_SIZE; i++)
        for(int j = 0; j < GLY_SIZE; j++)
            {   
                if(GridNodeMap[i][j][k]->id == -1)  // visualize nodes in close list only
                    visited_nodes.push_back(GridNodeMap[i][j][k]->coord);
            }
    ROS_WARN("visited_nodes size : %ld", visited_nodes.size());
    return visited_nodes;
}

Vector3d AstarPathFinder::gridIndex2coord(const Vector3i & index) //get every rect center coord
{
    Vector3d pt;

    pt(0) = ((double)index(0)) * resolution + gl_xl;
    pt(1) = ((double)index(1)) * resolution + gl_yl;
    pt(2) = 0;

    return pt;
}

Vector3i AstarPathFinder::coord2gridIndex(const Vector3d & pt) //get the index of rect
{
    Vector3i idx;
    idx <<  min( max( int( (pt(0) - gl_xl) * inv_resolution), 0), GLX_SIZE - 1),
            min( max( int( (pt(1) - gl_yl) * inv_resolution), 0), GLY_SIZE - 1),
            0;                  
  
    return idx;
}

Eigen::Vector3d AstarPathFinder::coordRounding(const Eigen::Vector3d & coord)
{
    return gridIndex2coord(coord2gridIndex(coord));
}

inline bool AstarPathFinder::isOccupied(const Eigen::Vector3i & index) const
{
    return isOccupied(index(0), index(1), index(2));
}


inline void AstarPathFinder::AstarGetSucc(GridNodePtr currentPtr, vector<GridNodePtr> & neighborPtrSets, vector<double> & edgeCostSets)
{   
    neighborPtrSets.clear();
   // ROS_INFO("succ");
    edgeCostSets.clear();
    Eigen::Vector3i temp_index;
    Eigen::Vector3d temp_coord; 
    int currentIndex_x = currentPtr->index(0);
    int currentIndex_y = currentPtr->index(1);
    int currentIndex_z = currentPtr->index(2);
    GridNodePtr tempGrid;
    for (int i = 1; i > -2; i--)
            {
                for(int j = 1; j > -2; j--)
                {
                    if ((i ==0 || j == 0) && i != j )//one can't be the successor of itself 
                    {
                        temp_index(0) = currentIndex_x + i;
                        temp_index(1) = currentIndex_y + j;
                        temp_index(2) = currentIndex_z;
                        // ROS_INFO("neighbor %d,%d,%d", temp_index(0), temp_index(1), temp_index(2));
                        if (temp_index(0) < GLX_SIZE && temp_index(0) >= 0 && temp_index(1) < GLY_SIZE && temp_index(1) >= 0)//index is in range(0,max_size)
                        {
                            
                            tempGrid =GridNodeMap[temp_index(0)][temp_index(1)][temp_index(2)];
                            // ROS_INFO(" id is %d", tempGrid -> id);
                            edgeCostSets.push_back(getHeu(currentPtr,tempGrid));
                            neighborPtrSets.push_back(tempGrid);  
    
                        }
                    
                    }
                }

            }
    
}

double AstarPathFinder::getHeu(GridNodePtr node1, GridNodePtr node2)
{
   double Heu = 0;
   for (int i = 1;i < 3;i++)
      {
          Heu += (node1->coord(i) - node2->coord(i))*(node1->coord(i) - node2->coord(i));
      }
    Heu = sqrt(Heu);
    //ROS_INFO("%lf",Heu);
    return Heu;
}
void AstarPathFinder::AstarGraphSearch(Vector3d start_pt, Vector3d end_pt)
{   
    ros::Time time_1 = ros::Time::now();    
 
    //index of start_point and end_point
    Vector3i start_idx = coord2gridIndex(start_pt);
    Vector3i end_idx   = coord2gridIndex(end_pt);
    goalIdx = end_idx;
    //position of start_point and end_point
    start_pt = gridIndex2coord(start_idx);
    end_pt   = gridIndex2coord(end_idx);

    //Initialize the pointers of struct GridNode which represent start node and goal node
    GridNodePtr startPtr = new GridNode(start_idx, start_pt);
    GridNodePtr endPtr   = new GridNode(end_idx,   end_pt);
    globalStartPtr = startPtr;
    ROS_INFO("AStar");
    //openSet is the open_list implemented through multimap in STL library
    openSet.clear();
    // currentPtr represents the node with lowest f(n) in the open_list
    GridNodePtr currentPtr  = NULL;
    GridNodePtr neighborPtr = NULL;

     
    startPtr -> gScore = 0;
    startPtr -> fScore = getHeu(startPtr,endPtr);   

    startPtr -> id = 1; 
    startPtr -> coord = start_pt;
    openSet.insert( make_pair(startPtr -> fScore, startPtr) );
    vector<GridNodePtr> neighborPtrSets;
    vector<double> edgeCostSets;
    vector<GridNodePtr> CloseSet;//new added vector for saving closed
    Eigen::Vector3i tempIdx;
    // this is the main loop
    while ( !openSet.empty() ){  
       currentPtr = openSet.begin()->second;//get the least key of OpenSet    
   
       currentPtr->id = -1;
       CloseSet.push_back(currentPtr);
       openSet.erase(openSet.begin());
        if( currentPtr->index == goalIdx ){
            ros::Time time_2 = ros::Time::now();
            terminatePtr = currentPtr;
            _start_pt(0) = currentPtr->index(0);
            _start_pt(1) = currentPtr->index(1);
            _start_pt(2) = currentPtr->index(2);
            ROS_WARN("[A*]{sucess}  Time in A*  is %f ms, path cost is %f m", (time_2 - time_1).toSec() * 1000.0, currentPtr->gScore * resolution );     
            return;
        }

        //get the succetion
        AstarGetSucc(currentPtr,neighborPtrSets, edgeCostSets);     

        for(int i = 0; i < (int)neighborPtrSets.size(); ++i){
            neighborPtr = neighborPtrSets[i];
            double heu = getHeu(neighborPtr,endPtr);
            double temp_g = currentPtr -> gScore + edgeCostSets[i];
            double temp_f = temp_g + heu;
            if(neighborPtr -> id == 0){ //discover a new node, which is not in the closed set and open set
                neighborPtr -> id = 1;
                neighborPtr -> cameFrom = currentPtr;
                neighborPtr -> gScore = temp_g;
                neighborPtr -> fScore = temp_f;
                openSet.insert( make_pair(neighborPtr -> fScore,neighborPtr));
                continue;
            }
            else if(neighborPtr->id == 1){ //this node is in open set and need to judge if it needs to update, the "0" should be deleted when you are coding

                for(std::multimap<double, GridNodePtr>::iterator nodeMapIt = openSet.begin(); nodeMapIt !=openSet.end();nodeMapIt++)
                {

                    if (nodeMapIt->second->index == neighborPtr->index)//search the same point
                    {
                        if (nodeMapIt->second->fScore > temp_f)
                        {
                            openSet.erase(nodeMapIt);
                            neighborPtr -> cameFrom = currentPtr;
                            neighborPtr -> gScore = temp_g;
                            neighborPtr -> fScore = temp_f;
                            openSet.insert( make_pair(neighborPtr -> fScore,neighborPtr));
                            break;
                        }
                    }
                    

                    continue;
                }
            }
            else{//this node is in closed set

               for (std::vector<GridNodePtr>::iterator it = CloseSet.begin(); it != CloseSet.end(); it++)
               {
                    if ((*it)->index == neighborPtr->index)//search the same point
                    {
                        if ((*it)->fScore > temp_f)
                        {
                            CloseSet.erase(it);
                            neighborPtr -> id = 1;
                            neighborPtr -> cameFrom = currentPtr;
                            neighborPtr -> gScore = temp_g;
                            neighborPtr -> fScore = temp_f;
                            openSet.insert( make_pair(neighborPtr -> fScore,neighborPtr));
                            break;

                        }
                    }         
               }
                continue;
            }
        }      
    }
    //if search fails
    ros::Time time_2 = ros::Time::now();
    if((time_2 - time_1).toSec() > 0.1)
        ROS_WARN("Time consume in Astar path finding is %f", (time_2 - time_1).toSec() );
}


vector<Vector3d> AstarPathFinder::getPath() 
{   
    vector<Vector3d> path;
    vector<GridNodePtr> gridPath;
    GridNodePtr  currentNode = terminatePtr;
   for(int i = 0; i < 10 ;i++)
   while(currentNode->index != globalStartPtr->index)
    {
        gridPath.push_back(currentNode);
        currentNode = currentNode->cameFrom;
    }
    gridPath.push_back(globalStartPtr);

    for (auto ptr: gridPath)
        path.push_back(ptr->coord);
    reverse(path.begin(),path.end());

    return path;
}