; Auto-generated. Do not edit!


(cl:in-package arm-msg)


;//! \htmlinclude converter.msg.html

(cl:defclass <converter> (roslisp-msg-protocol:ros-message)
  ((object
    :reader object
    :initarg :object
    :type arm-msg:coord
    :initform (cl:make-instance 'arm-msg:coord)))
)

(cl:defclass converter (<converter>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <converter>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'converter)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name arm-msg:<converter> is deprecated: use arm-msg:converter instead.")))

(cl:ensure-generic-function 'object-val :lambda-list '(m))
(cl:defmethod object-val ((m <converter>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm-msg:object-val is deprecated.  Use arm-msg:object instead.")
  (object m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <converter>) ostream)
  "Serializes a message object of type '<converter>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'object) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <converter>) istream)
  "Deserializes a message object of type '<converter>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'object) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<converter>)))
  "Returns string type for a message object of type '<converter>"
  "arm/converter")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'converter)))
  "Returns string type for a message object of type 'converter"
  "arm/converter")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<converter>)))
  "Returns md5sum for a message object of type '<converter>"
  "1431af4482a444b26905122d6a7f3716")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'converter)))
  "Returns md5sum for a message object of type 'converter"
  "1431af4482a444b26905122d6a7f3716")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<converter>)))
  "Returns full string definition for message of type '<converter>"
  (cl:format cl:nil "coord object~%~%================================================================================~%MSG: arm/coord~%int32 x~%int32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'converter)))
  "Returns full string definition for message of type 'converter"
  (cl:format cl:nil "coord object~%~%================================================================================~%MSG: arm/coord~%int32 x~%int32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <converter>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'object))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <converter>))
  "Converts a ROS message object to a list"
  (cl:list 'converter
    (cl:cons ':object (object msg))
))
