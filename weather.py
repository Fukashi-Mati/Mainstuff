from json import dumps
from kafka import KafkaProducer
from sense_emu import SenseHat
import time
def getAndSendTemperature(sense):

    temperature = sense.temp
    producer = KafkaProducer(bootstrap_servers=['192.168.0.103:9092'],
                         value_serializer=lambda x:
                         dumps(x).encode('utf-8'))
    producer.send('temp2', value={'temperatura': temperature})



sense = SenseHat()
while True:
    getAndSendTemperature(sense)
    sleep(30)