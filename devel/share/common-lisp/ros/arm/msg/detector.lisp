; Auto-generated. Do not edit!


(cl:in-package arm-msg)


;//! \htmlinclude detector.msg.html

(cl:defclass <detector> (roslisp-msg-protocol:ros-message)
  ((one
    :reader one
    :initarg :one
    :type arm-msg:coord
    :initform (cl:make-instance 'arm-msg:coord))
   (two
    :reader two
    :initarg :two
    :type arm-msg:coord
    :initform (cl:make-instance 'arm-msg:coord))
   (three
    :reader three
    :initarg :three
    :type arm-msg:coord
    :initform (cl:make-instance 'arm-msg:coord))
   (four
    :reader four
    :initarg :four
    :type arm-msg:coord
    :initform (cl:make-instance 'arm-msg:coord))
   (object
    :reader object
    :initarg :object
    :type arm-msg:coord
    :initform (cl:make-instance 'arm-msg:coord))
   (radius
    :reader radius
    :initarg :radius
    :type cl:fixnum
    :initform 0))
)

(cl:defclass detector (<detector>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <detector>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'detector)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name arm-msg:<detector> is deprecated: use arm-msg:detector instead.")))

(cl:ensure-generic-function 'one-val :lambda-list '(m))
(cl:defmethod one-val ((m <detector>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm-msg:one-val is deprecated.  Use arm-msg:one instead.")
  (one m))

(cl:ensure-generic-function 'two-val :lambda-list '(m))
(cl:defmethod two-val ((m <detector>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm-msg:two-val is deprecated.  Use arm-msg:two instead.")
  (two m))

(cl:ensure-generic-function 'three-val :lambda-list '(m))
(cl:defmethod three-val ((m <detector>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm-msg:three-val is deprecated.  Use arm-msg:three instead.")
  (three m))

(cl:ensure-generic-function 'four-val :lambda-list '(m))
(cl:defmethod four-val ((m <detector>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm-msg:four-val is deprecated.  Use arm-msg:four instead.")
  (four m))

(cl:ensure-generic-function 'object-val :lambda-list '(m))
(cl:defmethod object-val ((m <detector>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm-msg:object-val is deprecated.  Use arm-msg:object instead.")
  (object m))

(cl:ensure-generic-function 'radius-val :lambda-list '(m))
(cl:defmethod radius-val ((m <detector>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm-msg:radius-val is deprecated.  Use arm-msg:radius instead.")
  (radius m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <detector>) ostream)
  "Serializes a message object of type '<detector>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'one) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'two) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'three) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'four) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'object) ostream)
  (cl:let* ((signed (cl:slot-value msg 'radius)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <detector>) istream)
  "Deserializes a message object of type '<detector>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'one) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'two) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'three) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'four) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'object) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'radius) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<detector>)))
  "Returns string type for a message object of type '<detector>"
  "arm/detector")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'detector)))
  "Returns string type for a message object of type 'detector"
  "arm/detector")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<detector>)))
  "Returns md5sum for a message object of type '<detector>"
  "93aa21638d78edb37fecdca254769315")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'detector)))
  "Returns md5sum for a message object of type 'detector"
  "93aa21638d78edb37fecdca254769315")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<detector>)))
  "Returns full string definition for message of type '<detector>"
  (cl:format cl:nil "coord one~%coord two~%coord three~%coord four~%coord object~%int16 radius~%~%================================================================================~%MSG: arm/coord~%int32 x~%int32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'detector)))
  "Returns full string definition for message of type 'detector"
  (cl:format cl:nil "coord one~%coord two~%coord three~%coord four~%coord object~%int16 radius~%~%================================================================================~%MSG: arm/coord~%int32 x~%int32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <detector>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'one))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'two))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'three))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'four))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'object))
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <detector>))
  "Converts a ROS message object to a list"
  (cl:list 'detector
    (cl:cons ':one (one msg))
    (cl:cons ':two (two msg))
    (cl:cons ':three (three msg))
    (cl:cons ':four (four msg))
    (cl:cons ':object (object msg))
    (cl:cons ':radius (radius msg))
))
