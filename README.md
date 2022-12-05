# IntelliGF

code sources:
- https://www.kaggle.com/datasets/asdasdasasdas/garbage-classification/code

FINAL REPORT:
1. Introduction  

One of the common goals at the University of Waterloo is to support SDGs in a campaign known as “Shift Zero”. Specifically, there are five areas of focus: engaging and training, reducing and eliminating waste, maximizing recycling, capturing organics, and expanding reuse programs. Ultimately, the goal is to attain a 90% diversion rate by 2035, achieving a zero-waste campus. 

Unfortunately, students and staff seem to often disregard this matter; our subpar awareness of the importance of waste management and its future effects are concerning. Whether the reason (e.x. academics, extracurricular activities) or location (e.x. cafeterias or dorm rooms), we have undoubtedly belittled its significance – this project serves as its solution.  

Brainstorming possible ideas that relate to technology, our final solution was targeted at the root of the issue: as individuals throw out garbage. Specifically, IntelliGF, the name of our garbage classification device, serves to limit the inaccuracies we first make when disposing of waste into incorrect bins. After all, the effects of unclassified garbage increase in magnitude as they go further down the (waste disposal) route, later being recycled, treated thermally, or deposited in a landfill. Needless to say, the technologies required to ameliorate this problem at that stage would be onerous, especially considering the more efficient solution from IntelliGF.  

 

2. Background Research 

There existed two main gaps of knowledge when we began working on this project: machine learning and most of the hardware components. Understandably, these areas are where we conducted the most research.  

In terms of software, we first watched basic (but long) videos about general machine learning terminology and implementation in PyTorch. Videos we watched include “Deep Learning with Pytorch” or “Image Classification with Convolutional Neural Networks | Deep Learning with PyTorch: Zero to GANs”. We also learned from online sources such as PyTorch documentation or Tutorialspoint’s machine-learning articles. After attempting to build our own model, our accuracy level was only 60% when evaluating three different groups; the model was either very much overfitting or underfitting and modifying the hyperparameters did not serve as much aid. Consequently, we resorted to using an ML model we found online on Kaggle that predicted six classes at around 96%.  

For hardware, most of us had very little experience and knowledge working with any sort of microcontrollers, motors, or wires. As a result, we had to start very basic. We began by reading a list of Wikipedia articles and YouTube videos to gain a rudimentary understanding of the Arduino and the other hardware parts we needed for this project. Upon purchasing and borrowing the necessary hardware, we attached the components together using a user’s manual and online tutorials. To code the INO file, we read the documentation of the Stepper.h library. 

Note that this section does not provide all the sources we used for this project. For an exhaustive list, refer to the “References” section.  

 

3. Implementation 

Most of the group members had little knowledge and experience of working with the technologies we ultimately applied to our project, including (but not limited to) machine learning and microcontrollers (i.e., an Arduino). However, we decided to challenge ourselves because learning about these technologies coupled with the hope of finally building this idea to life was worth the laborious research we knew we had to conduct.  

At the start, the path towards completion was foggy, so we watched some YouTube videos and read over dozens of online sources to finally grasp an understanding of how to implement our idea. Little by little, software and hardware began to work separately, so we began to integrate both together via a middleware. The physical design was added at the end, where we tested with different materials and decided on which material works best with respect to the limitations of the stepper motor.  

The software component, specifically, is composed of a Pytorch ML model that trains on a large Kaggle dataset composed of thousands of images. The camera module is accessed in the main notebook in block “In [74]”. The image is then pre-processed by Pytorch functions, which undergoes deep learning using the ResNet-50 Convolutional Neural Network. The Kaggle model class ensures that the data classification conforms more with our expected results. After the model predicts the type of material, that prediction is passed to an external Flask server that acts as a middleware, which is finally retrieved from the Arduino and to the rest of the hardware.  

On the hardware side, our group had little to no experience working with Arduinos or motors, so we had to climb a steep learning curve over the past few months. Our design presented us with a general challenge that we had to overcome: the ability to rotate a disk for some number of degrees, consistently and accurately. By reading a lot of Wikipedia articles and learning how motors work, we chose to use a 28BYJ-48 Stepper Motor, with a voltage of 5 volts. The BYJ-48 was the most convenient option for our stepper motor due to its compatibility with an Arduino and accuracy when it comes to the number of rotations. More specifically, a stepper motor rotates in steps, allowing us to precisely make rotations, making it the most viable option. Additionally, we needed to 3D print an adapter for the stepper motor since it is unreliable to rotate a disk over a small surface area. After mismeasuring the dimensions of the adapter multiple times, we finally 3D-printed an adapter for the motor that allowed us to distribute the force over a larger surface area. From here, we were able to hot glue our revolving disk onto the 3D adapter. At this point, we were able to control the direction and number of degrees our disk rotated at, and since we wanted to classify garbage in 3 different bins, we created 3 equally spaced holes on our disk. The hardware component of this project was not simple, the design went over multiple iterations and we had to utilize engineering principles to make sure our contraption was working consistently and accurately. However, hardware is rendered useless without its corresponding software and proper integration. Integrating every together was truly challenging, but fun. We exercised different methods and decided that building a backend API that acts as middleware between the Arduino and ML model was the most efficient and reliable way.  

The figure below shows a visual representation of the integration between all systems in IntelliGF: 



4. Group members' contribution 

Aditya: Built and integrated all the hardware (e.x. Arduino, stepper motor, breadboard); researched and sketched possible designs for efficient integration between hardware and base; recorded and filmed portions of the video. 

 

Terry: Built preliminary models using TensorFlow as “proof of concept” and used matplotlib to graph associated metrics for evaluation; Coded PyTorch functions and trained a sourced ML model; tested ML model with materials to ensure accuracy; used IPython.display to connect notebook kernel with external camera for live predictions; researched and found a large and appropriate dataset to train ML model; built some backend API endpoints to connect to Colab notebook to Python script behind the software; recorded and filmed portions of the video; wrote project prototype document. 

 

Richard: Researched and sketched possible designs for efficient integration between hardware and base; learned PyTorch to code an ML model (inaccurate so wasn’t used); wrote the final report; wrote meeting minutes for weekly Sunday meetings; recorded and filmed portions of the video; helped to construct the base; wrote project prototype document. 

 

Eric: Introduced and helped design the idea of the rotating garbage filter mechanism; helped with the building of the base; directed the production of the video; edited the final video; designed logo for IntelliGF; ran and developed an ML model built in TensorFlow (overfitted so was not used). Helped with the development of the Flask endpoints. 

 

Matthew: Researched and sketched possible designs for efficient integration between hardware and base; proposed possible problems with hardware and solutions to the problems if/when encountered; assisted with hardware; proposed possible solutions encountered during the development of software. 

 

5. Final Product Evaluation 

Generally, we are all very satisfied with our work. Although the appearance of the final product and the goal we had in mind differed, that discrepancy results mainly from our prior inexperience and underestimation of the difficulty of the project.  

With respect to the software side, objectively speaking, the model ended up working better than all members expected. After many failed attempts, we take some pride in the fact that it functions with such a high level of accuracy. That being said, our initial goal to generalize the product failed. For instance, it classifies six different types of garbage. However, due to its low versatility, if a different (or worse, a new) object was to be trained, then a whole new data set would be required. In the real world, this would be a huge hassle to deal with. Furthermore, we did not employ a sensor system, which somewhat defeats the purpose of this project because it requires one to physically take a picture. In other words, it takes one more time to load the model and wait for the device to turn, than to mentally analyze the correct bin and throw out the waste accordingly.  

With respect to the hardware side, the product’s performance almost replicates our original goal. With the help of the stepper motor, the Arduino turns the revolving base properly and precisely (albeit slowly), and it connects well with all other parts of the hardware. Of course, the design of the bin could be improved (refer to “Future Work”), but we were greatly limited by the hardware models we were using. Nevertheless, the project functions and is durable, and it can sustain the weight of light objects.  

All in all, despite the small differences between our original vision of our final product and the version that we have built, we have all learned a lot from this project – from start to end. We mastered technologies we have never previously used, and IntelliGF behaves properly.  

 

6. Design Trade-offs 

One of the initial goals was to build the base purely out of wood. However, the weight of wood is far greater than what the stepper motor could handle, and trial and error would require an expense none of us were eager to invest in. We figured that cardboard – a durable material that would ultimately serve the same purpose as wood, but significantly lighter – would suit better as the base. Of course, with better resources, the quality would be better (refer to “Future Work” section). 

Another main design trade off was the fact that our project used motors over flaps. While flaps would work faster, after conducting some research, it became evident that they were not only much more costly (since it would require flaps and motors), but they would have been much harder to implement.  

 

7. Future Work 

Looking at the current state of our project, two areas that could use evident improvement were scalability and generalization. Concerning the former, using a laptop camera and taking a photo every time a piece of garbage is about to be thrown out is inefficient and arguably more tedious than using a regular garbage can. However, changes such as real-time detection and faster data pipelines could give real tangible purpose to our project. For the latter, due to the chosen dataset that our model trained on, only 6 different classes of garbage can be detected with accuracy. In reality, with a large variety of common garbage, general classification is an ongoing issue that we still haven't resolved. These ideas can be further elaborated in terms of software and hardware respectively.  

There are a few notable points to improve the software. The most evident, firstly, would be to add real-time detection. Near the start of the project, we tried to integrate a trained machine-learning model with real-time classification using TensorFlow and OpenCV. Unfortunately, this attempt was not successful and lead to a pivot in terms of how we were planning on using the classification model; more specifically, we resorted to static classification. In the future, giving a second shot at real-time usage is one main point entry to evolving the project. Furthermore, even if we continue working with the current model we have, we could try playing around with the model structure (such as unfreezing some layers from ResNet so that we can apply fine-tuning) or opting for a more general model in the first place – one that can classify images of garbage into their respective bins right away rather than identifying the name of the garbage than mapping it to it type manually. Finally, we could make a faster data pipeline. Instead of using a REST API, we could further the idea of “real-time” data transfer by using web sockets for immediate action-reaction effects.  

For hardware on the other hand, there are two key remarks. Firstly, better and more durable materials could have been used; for example, one option was to build a wooden base. Thinking even long term, other outdoor resistant materials are also alternatives. Adding on to the issue of a slow UX, the stepper motor spins relatively slow; in this regard, one of the designs we made in the brainstorming process (controlling flaps) may be a more scalable choice.  

Who knows? We could always return to continue working on this project sometime down the line. 

 

8. References 

Components101. “28BYJ-48 - 5V Stepper Motor.” Components101, 5 Mar. 2021, https://components10 1.com/motors/28byj-48-stepper-motor. 

Pytorch Contributors. “PYTORCH Documentation.” PyTorch Documentation - PyTorch 1.13 Documentation, https://pytorch.org/docs/stable/index.html. 

s16h, and Shahzaib Ali. “Flask Example with Post.” Stack Overflow, 8 Apr. 2014, https://stackoverflow.c om/questions/22947905/flask-example-with-post. 

 
