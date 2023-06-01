# ACMM
Smart Kitchen Robot - Automatic Stuffed Roti cooking robot

## Abstract:
This project is aimed at making the cooking process easier by making parathas, stuffing them and baking them from scratch. The functioning can be divided into 3 stages. In the first stage called mixing, flour and water can be filled into the upper open jars in required quantities based on the number of rotis required. The exact amount needed for one roti is already programmed and the mixing process for the same happens in the second level of the product. The linear actuator is used alongside to provide a strong base for the water leak-proof jar to mix in the second level of the product. The second stage is called encrusting. Here the required stuffing is taken from a separate jar provided along side the flour and water container on the first level of the product. An automated cutter is employed that makes sure only the required quantity of the stuffing falls in the third container. The dough ball from the second level is transported into the third container in the third level using an automated L - shape arm. The doughball is mixed with the stuffing in the third level. The third stage is called baking stage. Here an inverted linear actuator is used to help the round heater compress the doughball into a roti shape. The heating process starts simultaneously and the paratha is baked at predetermined temperature. It is then pushed into a hot pack and the process continuous from the first stage.

## Keywords/Components Used:
 * 12V DC motor 500 RPM for Linear Actuator 
 * 12V DC motor 200 RPM for atta distribution 
 * Johnson Geared DC motor 12V 60 RPM for atta kneading
 * Kamoer 12V 60ml/min peristaltic pump for water container
 * Kamoer 12V 37ml/min peristaltic pump for oil container 
 * Screw feeder mechanism for dispensing stuffing material and dough ball making 
 * Johnson geared DC motor 12V 60 RPM for screw feeder 
 * SG90 servo motor for stuffing cutter 
 * Tower Pro MG995 metal gear servo for L-Type arm 
 * E18-D80NK infrared sensor for dough ball detection 
 * Optical end stop limit switch for linear actuator end detection 
 * Heating coils and Thermistor for baking stage.

## Working Principle:
The working principle of our Aloo Chappati preparation system involves precise control over the timing of actuator strikes. By carefully tuning the timing, we ensure that the chappatis are cooked to perfection. In addition, we have incorporated advanced sensors, including IR sensors and weightsensors, to provide real-time feedback and ensure the presence of the substance in the container during the cooking process. The IR sensors help monitor the temperature and detect any anomalies, while the weightsensors verify the presence and quantity of the ingredients.

## Future Work:
* In order to further enhance the performance and functionality of our system, we have identified several areas for future work. Firstly, we plan to integrate an Internet of Things (IoT) module into our system. This will allow us to gather and analyze data from the cooking process, providing enhanced feedback to the user and enabling remote monitoring and control.
* Secondly, we aim to transition from timer-based operations to sensor-based feedback. Instead of relying solely on pre-determined timings, we will utilize the data from the IR sensors and weightsensors to dynamically adjust the cooking parameters. This adaptive approach will result in more precise and consistent cooking outcomes.
* Lastly, we intend to implement a reliable machine learning (ML) algorithm into our system. By training the algorithm on a large dataset of cooking parameters and corresponding chappati quality, we can create a model that can accurately predict the optimal cooking settings for different scenarios. This will further improve the consistency and accuracy of our Aloo Chappati preparation system, ensuring that the end product meets the desired standards every time.

Through these future advancements, we aim to create an even more efficient, automated, and user-friendly Aloo Chappati preparation system that delivers consistently delicious chappatis with minimal effort and maximum reliability.


