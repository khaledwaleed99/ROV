import cv2
import os

mainFolder = 'Images'
myFolders = os.listdir(mainFolder)
print(myFolders)
for folder in myFolders:
    path = mainFolder + '/' + folder
    images = []
    mylist = os.listdir(path)
    print(f'Total no of images detected{len(mylist)}')
    for imgN in mylist:
       curImg = cv2.imread(f'{path}/{imgN}')
       curImg = cv2.resize(curImg, (0, 0), None, 0.5, 0.5)
       images.append(curImg)

    stitcher = cv2.Stitcher.create()
    (status, result) = stitcher.stitch(images)
    if (status == cv2.Stitcher_OK):
        print('panorama generated')
        cv2.imshow(folder, result)
        cv2.waitKey(0)
    else: print('panorama generation unsuccessful')
