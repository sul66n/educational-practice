import cv2
import numpy as np

scale = 0.7  # масштаб всех изображений

image = cv2.imread("test2.jpg")
image_resized = cv2.resize(image, (0, 0), fx=scale, fy=scale)
cv2.imshow("Original", image_resized)
cv2.waitKey(0)

blurred_image = cv2.GaussianBlur(image, (11, 11), 0)
hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)

hsv_min = np.array([36, 25, 25], np.uint8)
hsv_max = np.array([70, 255, 255], np.uint8)
green_mask = cv2.inRange(hsv_image, hsv_min, hsv_max)

green_mask_resized = cv2.resize(green_mask, (0, 0), fx=scale, fy=scale)
cv2.imshow("Mask of green", green_mask_resized)
cv2.waitKey(0)

contours = cv2.findContours(green_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
min_area = 500

for contour in contours:
    if cv2.contourArea(contour) > min_area:
        x, y, w, h = cv2.boundingRect(contour)
        center_x = int(x + w / 2)
        center_y = int(y + h / 2)
        cv2.circle(image, (center_x, center_y), 5, (0, 0, 255), -1)

filtered_contours = [c for c in contours if cv2.contourArea(c) > min_area]
cv2.drawContours(image, filtered_contours, -1, (0, 255, 0), 2)

result_resized = cv2.resize(image, (0, 0), fx=scale, fy=scale)
cv2.imshow("Result", result_resized)
cv2.waitKey(0)
cv2.destroyAllWindows()
