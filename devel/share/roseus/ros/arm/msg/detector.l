;; Auto-generated. Do not edit!


(when (boundp 'arm::detector)
  (if (not (find-package "ARM"))
    (make-package "ARM"))
  (shadow 'detector (find-package "ARM")))
(unless (find-package "ARM::DETECTOR")
  (make-package "ARM::DETECTOR"))

(in-package "ROS")
;;//! \htmlinclude detector.msg.html


(defclass arm::detector
  :super ros::object
  :slots (_one _two _three _four _object _radius ))

(defmethod arm::detector
  (:init
   (&key
    ((:one __one) (instance arm::coord :init))
    ((:two __two) (instance arm::coord :init))
    ((:three __three) (instance arm::coord :init))
    ((:four __four) (instance arm::coord :init))
    ((:object __object) (instance arm::coord :init))
    ((:radius __radius) 0)
    )
   (send-super :init)
   (setq _one __one)
   (setq _two __two)
   (setq _three __three)
   (setq _four __four)
   (setq _object __object)
   (setq _radius (round __radius))
   self)
  (:one
   (&rest __one)
   (if (keywordp (car __one))
       (send* _one __one)
     (progn
       (if __one (setq _one (car __one)))
       _one)))
  (:two
   (&rest __two)
   (if (keywordp (car __two))
       (send* _two __two)
     (progn
       (if __two (setq _two (car __two)))
       _two)))
  (:three
   (&rest __three)
   (if (keywordp (car __three))
       (send* _three __three)
     (progn
       (if __three (setq _three (car __three)))
       _three)))
  (:four
   (&rest __four)
   (if (keywordp (car __four))
       (send* _four __four)
     (progn
       (if __four (setq _four (car __four)))
       _four)))
  (:object
   (&rest __object)
   (if (keywordp (car __object))
       (send* _object __object)
     (progn
       (if __object (setq _object (car __object)))
       _object)))
  (:radius
   (&optional __radius)
   (if __radius (setq _radius __radius)) _radius)
  (:serialization-length
   ()
   (+
    ;; arm/coord _one
    (send _one :serialization-length)
    ;; arm/coord _two
    (send _two :serialization-length)
    ;; arm/coord _three
    (send _three :serialization-length)
    ;; arm/coord _four
    (send _four :serialization-length)
    ;; arm/coord _object
    (send _object :serialization-length)
    ;; int16 _radius
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; arm/coord _one
       (send _one :serialize s)
     ;; arm/coord _two
       (send _two :serialize s)
     ;; arm/coord _three
       (send _three :serialize s)
     ;; arm/coord _four
       (send _four :serialize s)
     ;; arm/coord _object
       (send _object :serialize s)
     ;; int16 _radius
       (write-word _radius s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; arm/coord _one
     (send _one :deserialize buf ptr-) (incf ptr- (send _one :serialization-length))
   ;; arm/coord _two
     (send _two :deserialize buf ptr-) (incf ptr- (send _two :serialization-length))
   ;; arm/coord _three
     (send _three :deserialize buf ptr-) (incf ptr- (send _three :serialization-length))
   ;; arm/coord _four
     (send _four :deserialize buf ptr-) (incf ptr- (send _four :serialization-length))
   ;; arm/coord _object
     (send _object :deserialize buf ptr-) (incf ptr- (send _object :serialization-length))
   ;; int16 _radius
     (setq _radius (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get arm::detector :md5sum-) "93aa21638d78edb37fecdca254769315")
(setf (get arm::detector :datatype-) "arm/detector")
(setf (get arm::detector :definition-)
      "coord one
coord two
coord three
coord four
coord object
int16 radius

================================================================================
MSG: arm/coord
int32 x
int32 y

")



(provide :arm/detector "93aa21638d78edb37fecdca254769315")


