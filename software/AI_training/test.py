from ultralytics import YOLO
import cv2

# Load a pretrained model
model = YOLO("yolo11s.pt")

# Train the model on your custom dataset
#model.train(data="configs.yaml", epochs=100, imgsz=640)
image = model.predict('C:/Users/OBR/Documents/ABC/where.jpg', imgsz = 640)


for i in image:
    im_array = i.plot()
    cv2.imshow("Resultado", im_array)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
