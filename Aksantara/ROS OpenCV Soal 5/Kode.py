import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt
 
img = cv.imread('C:\Aksantara\Soal 5\contoh.jpg', cv.IMREAD_GRAYSCALE) #Path yang digunakan berdasarkan path di komputer saya
 
orb = cv.ORB_create()
 
keypoint = orb.detect(img,None)
 
keypoint, des = orb.compute(img, keypoint)
 
hasil = cv.drawKeypoints(img, keypoint, None, color=(0,255,0), flags=0)
plt.imshow(hasil), plt.show()