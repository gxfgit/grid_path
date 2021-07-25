; Auto-generated. Do not edit!


(cl:in-package grid_path_searcher-srv)


;//! \htmlinclude get_plan-request.msg.html

(cl:defclass <get_plan-request> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0))
)

(cl:defclass get_plan-request (<get_plan-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <get_plan-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'get_plan-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name grid_path_searcher-srv:<get_plan-request> is deprecated: use grid_path_searcher-srv:get_plan-request instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <get_plan-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader grid_path_searcher-srv:x-val is deprecated.  Use grid_path_searcher-srv:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <get_plan-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader grid_path_searcher-srv:y-val is deprecated.  Use grid_path_searcher-srv:y instead.")
  (y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <get_plan-request>) ostream)
  "Serializes a message object of type '<get_plan-request>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <get_plan-request>) istream)
  "Deserializes a message object of type '<get_plan-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<get_plan-request>)))
  "Returns string type for a service object of type '<get_plan-request>"
  "grid_path_searcher/get_planRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'get_plan-request)))
  "Returns string type for a service object of type 'get_plan-request"
  "grid_path_searcher/get_planRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<get_plan-request>)))
  "Returns md5sum for a message object of type '<get_plan-request>"
  "647c71abdcf22e8d9ecf2dcc45d55169")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'get_plan-request)))
  "Returns md5sum for a message object of type 'get_plan-request"
  "647c71abdcf22e8d9ecf2dcc45d55169")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<get_plan-request>)))
  "Returns full string definition for message of type '<get_plan-request>"
  (cl:format cl:nil "float64 x~%float64 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'get_plan-request)))
  "Returns full string definition for message of type 'get_plan-request"
  (cl:format cl:nil "float64 x~%float64 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <get_plan-request>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <get_plan-request>))
  "Converts a ROS message object to a list"
  (cl:list 'get_plan-request
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
))
;//! \htmlinclude get_plan-response.msg.html

(cl:defclass <get_plan-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:string
    :initform ""))
)

(cl:defclass get_plan-response (<get_plan-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <get_plan-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'get_plan-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name grid_path_searcher-srv:<get_plan-response> is deprecated: use grid_path_searcher-srv:get_plan-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <get_plan-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader grid_path_searcher-srv:result-val is deprecated.  Use grid_path_searcher-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <get_plan-response>) ostream)
  "Serializes a message object of type '<get_plan-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'result))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'result))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <get_plan-response>) istream)
  "Deserializes a message object of type '<get_plan-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'result) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'result) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<get_plan-response>)))
  "Returns string type for a service object of type '<get_plan-response>"
  "grid_path_searcher/get_planResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'get_plan-response)))
  "Returns string type for a service object of type 'get_plan-response"
  "grid_path_searcher/get_planResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<get_plan-response>)))
  "Returns md5sum for a message object of type '<get_plan-response>"
  "647c71abdcf22e8d9ecf2dcc45d55169")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'get_plan-response)))
  "Returns md5sum for a message object of type 'get_plan-response"
  "647c71abdcf22e8d9ecf2dcc45d55169")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<get_plan-response>)))
  "Returns full string definition for message of type '<get_plan-response>"
  (cl:format cl:nil "string result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'get_plan-response)))
  "Returns full string definition for message of type 'get_plan-response"
  (cl:format cl:nil "string result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <get_plan-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'result))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <get_plan-response>))
  "Converts a ROS message object to a list"
  (cl:list 'get_plan-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'get_plan)))
  'get_plan-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'get_plan)))
  'get_plan-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'get_plan)))
  "Returns string type for a service object of type '<get_plan>"
  "grid_path_searcher/get_plan")