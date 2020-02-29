import cv2


# Finding a reference point
def reference_point_search(image, x0, y0, x1, y1):
    for i in range(y0, y1, 1):
        for j in range(x0, x1, 1):
            if image[ i ][ j ][ 2 ] > 90 and image[ i ][ j ][ 0 ] < 75 and image[ i ][ j ][ 1 ] < 75:
                return i, j


# Finding center of the figure
def figure_center_search(image, height, width):
    i = 0
    j = 0
    while i < height:
        while j < width:
            if image[ i ][ j ][ 2 ] < 60 and image[ i ][ j ][ 0 ] < 60 and image[ i ][ j ][ 1 ] < 60:
                n = i
                m = j
                while image[ i ][ j ][ 0 ] < 60 and image[ i ][ j ][ 1 ] < 60 and image[ i ][ j ][ 2 ] < 60:
                    j += 1
                center_y = (j + m) / 2
                j = center_y
                while image[ i ][ j ][ 0 ] < 60 and image[ i ][ j ][ 1 ] < 60 and image[ i ][ j ][ 2 ] < 60:
                    i += 1
                center_x = (n + i) / 2
                return center_x, center_y
            else:
                j += 1
        i += 1
        j = 0


# Finding center of the figure
def figure_radius_search(image, height, width, center_x, center_y):
    j, i = center_y, center_x
    while i < height:
        while j < width:
            if image[ i ][ j ][ 2 ] < 60 and image[ i ][ j ][ 0 ] < 60 and image[ i ][ j ][ 1 ] < 60:
                radius = 1
                while image[ i ][ j ][ 0 ] < 60 and image[ i ][ j ][ 1 ] < 60 and image[ i ][ j ][ 2 ] < 60:
                    j += 1
                    radius += 1
                return radius
            else:
                j += 1


cap = cv2.VideoCapture(0)
while True:
    ret, img = cap.read()   
    img_info = list(img.shape)
    A = reference_point_search(img, 0, img_info[ 0 ] // 2, img_info[ 1 ] // 2, img_info[ 0 ])
    B = reference_point_search(img, 0, 0, img_info[ 1 ] // 2, img_info[ 0 ] // 2)
    C = reference_point_search(img, img_info[ 1 ] // 2, 0, img_info[ 1 ] - 1, img_info[ 0 ] // 2)
    D = reference_point_search(img, img_info[ 1 ] // 2, img_info[ 0 ] // 2, img_info[ 1 ], img_info[ 0 ])
    center = figure_center_search(img, img_info[ 0 ], img_info[ 1 ])
    if center is None:
        print ("The figure is missing")
    elif A is None:
        print ("The A point is missing")
    elif B is None:
        print ("The B point is missing")
    elif C is None:
        print ("The C point is missing")
    elif D is None:
        print ("The D point is missing")
    else:
        radius = figure_radius_search(img, img_info[ 0 ], img_info[ 1 ], center[ 0 ], center[ 1 ])
        print ("Center of figures:" + str(center))
        print ("Radius of figures:" + str(radius))       
        print ("First reference point:" + str(A))
        print ("Second reference point:" + str(B))
        print ("Third reference point:" + str(C))
        print ("Fourth reference point:" + str(D))
    ch = cv2.waitKey(5)
    if ch == 27:
        break

cap.release()
