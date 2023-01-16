from json import dumps
from kafka import KafkaProducer
from sense_emu import SenseHat
import time
import sys
def getAndSendTemperature(sens):

    temperature = sens.temp

    #producer = KafkaProducer(bootstrap_servers=['192.168.0.103:9092'],
                     #    value_serializer=lambda x:
                    #     dumps(x).encode('utf-8'))
    #producer.send('temp2', value={'temperatura': temperature})
    KAFKA_HOST = "192.168.0.103:9092"

    client = KafkaClient(hosts=KAFKA_HOST)
    topic = client.topics["temp2"]

    with topic.get_sync_producer() as producer:
        message = string(temperature)
        encoded_message = message.encode("utf-8")
        producer.produce(encoded_message)


sense = SenseHat()
num = sys.argv[1]
num2 = 0
while True:
    if num <= num2:
        num2 = 0
    else:
        getAndSendTemperature(sense)
        print("wysylam")
        num2 += 1
    sleep(1)
