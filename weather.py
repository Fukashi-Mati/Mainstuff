from kafka import KafkaProducer
from sense_emu import SenseHat
import time
import sys
def getAndSendTemperature(sense):

    temperature = sense.temp
    kafkaBrokers = '192.168.0.105:9092'
    caRootLocation = 'CARoot.pem'
    certLocation = 'certificate.pem'
    keyLocation = 'key.pem'
    topic = 'temp2'
    password = 'student123'

    producer = KafkaProducer(bootstrap_servers=kafkaBrokers,
                             security_protocol='SSL',
                             ssl_check_hostname=True,
                             ssl_cafile=caRootLocation,
                             ssl_certfile=certLocation,
                             ssl_keyfile=keyLocation,
                             ssl_password=password)

    producer.send(topic, bytes(str(temperature), 'utf-8'))
    producer.flush()


sense = SenseHat()
num = int(sys.argv[1])
num2 = 0
while True:
    if num <= num2:
        num2 = 0
    else:
        getAndSendTemperature(sense)
        num2 += 1
    time.sleep(1)
