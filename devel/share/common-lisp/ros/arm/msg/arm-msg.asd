
(cl:in-package :asdf)

(defsystem "arm-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "coord" :depends-on ("_package_coord"))
    (:file "_package_coord" :depends-on ("_package"))
    (:file "detector" :depends-on ("_package_detector"))
    (:file "_package_detector" :depends-on ("_package"))
  ))