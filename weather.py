from pykafka import KafkaClient, SslConfig
from sense_emu import SenseHat
import time
import sys
def getAndSendTemperature(sens):

    temperature = 25
    KAFKA_HOST = "192.168.0.103:9092"
    config = SslConfig(cafile='CARoot.pem',
                       certfile='certificate.pem',
                       keyfile='key.pem')
    client = KafkaClient(hosts=KAFKA_HOST, ssl_config=config)
    topic = client.topics["temp2"]

    with topic.get_sync_producer() as producer:
        message = str(temperature)
        encoded_message = message.encode("utf-8")
        producer.produce(encoded_message)


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