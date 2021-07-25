;; Auto-generated. Do not edit!


(when (boundp 'grid_path_searcher::test)
  (if (not (find-package "GRID_PATH_SEARCHER"))
    (make-package "GRID_PATH_SEARCHER"))
  (shadow 'test (find-package "GRID_PATH_SEARCHER")))
(unless (find-package "GRID_PATH_SEARCHER::TEST")
  (make-package "GRID_PATH_SEARCHER::TEST"))
(unless (find-package "GRID_PATH_SEARCHER::TESTREQUEST")
  (make-package "GRID_PATH_SEARCHER::TESTREQUEST"))
(unless (find-package "GRID_PATH_SEARCHER::TESTRESPONSE")
  (make-package "GRID_PATH_SEARCHER::TESTRESPONSE"))

(in-package "ROS")





(defclass grid_path_searcher::testRequest
  :super ros::object
  :slots (_x _y ))

(defmethod grid_path_searcher::testRequest
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:serialization-length
   ()
   (+
    ;; float64 _x
    8
    ;; float64 _y
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass grid_path_searcher::testResponse
  :super ros::object
  :slots (_result ))

(defmethod grid_path_searcher::testResponse
  (:init
   (&key
    ((:result __result) "")
    )
   (send-super :init)
   (setq _result (string __result))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; string _result
    4 (length _result)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _result
       (write-long (length _result) s) (princ _result s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _result
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _result (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass grid_path_searcher::test
  :super ros::object
  :slots ())

(setf (get grid_path_searcher::test :md5sum-) "647c71abdcf22e8d9ecf2dcc45d55169")
(setf (get grid_path_searcher::test :datatype-) "grid_path_searcher/test")
(setf (get grid_path_searcher::test :request) grid_path_searcher::testRequest)
(setf (get grid_path_searcher::test :response) grid_path_searcher::testResponse)

(defmethod grid_path_searcher::testRequest
  (:response () (instance grid_path_searcher::testResponse :init)))

(setf (get grid_path_searcher::testRequest :md5sum-) "647c71abdcf22e8d9ecf2dcc45d55169")
(setf (get grid_path_searcher::testRequest :datatype-) "grid_path_searcher/testRequest")
(setf (get grid_path_searcher::testRequest :definition-)
      "float64 x
float64 y
---
string result

")

(setf (get grid_path_searcher::testResponse :md5sum-) "647c71abdcf22e8d9ecf2dcc45d55169")
(setf (get grid_path_searcher::testResponse :datatype-) "grid_path_searcher/testResponse")
(setf (get grid_path_searcher::testResponse :definition-)
      "float64 x
float64 y
---
string result

")



(provide :grid_path_searcher/test "647c71abdcf22e8d9ecf2dcc45d55169")


