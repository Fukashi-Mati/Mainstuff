import os
import discord
import time
import bs4
import requests
import asyncio

async def check(act):
  while True:
    page = requests.get('https://www.g-status.com/en-gb/game/aion')
    strona = bs4.BeautifulSoup(page.content, 'html.parser')
    lista = strona.find_all('div')
    liczba = 0
    
    for a in lista:
      if (a.get_text() == 'ONLINE'):
        liczba += 1
    if(liczba  > 7 and act % 2 == 0):
      return 
    if(liczba < 5 and act % 2 == 1):
      return

    await asyncio.sleep(10)
    

def check1():
    page = requests.get('https://www.g-status.com/en-gb/game/aion')
    strona = bs4.BeautifulSoup(page.content, 'html.parser')
    lista = strona.find_all('div')
    liczba = 0
    for a in lista:
      if (a.get_text() == 'ONLINE'):
        liczba += 1
   
    return liczba
def check3(server):
  page = requests.get('https://www.g-status.com/en-gb/game/aion')
  strona = bs4.BeautifulSoup(page.content, 'html.parser')
  lista = strona.find_all('div')
  if(server == 'si'):
    odp = lista[121].get_text()
    return odp
  elif(server == 'st'):
    odp = lista[130].get_text()
    return odp

  
client = discord.Client()


@client.event
async def on_ready():
  print('Hai {0.user}'.format(client))
  status = 1
  while True:
    await check(status)
    status += 1
    if(status % 2 == 0):
      print('down')
      await client.get_channel(806508096654278696).send("@here Servers are offline")
      await client.get_channel(784817234220285995).send("@here Servers are offline")
    elif(status % 2 == 1):
      print('up')
      await client.get_channel(806508096654278696).send("@here Servers are online")
      await client.get_channel(784817234220285995).send("@here Servers are online")
    
    
@client.event
async def on_message(message):
  if message.content.startswith('!check'):
    await message.channel.send('Checking you lazy ass!')
    temp = check1()
    if(temp > 7):
      await message.channel.send('Its running')
    elif(temp > 3):
      await message.channel.send('Some are running, but idk which')
    elif(temp < 4):
      await message.channel.send('Its not running')
  if(message.content.startswith('dupa')):
     await message.channel.send('słonia')
     await message.channel.send('2')
  if(message.content.startswith('!sillus')):
     await message.channel.send(check3('si'))
  if(message.content.startswith('!storm')):
     await message.channel.send(check3('st'))

client.run('ODU3MTkxNjQwNDM5MzI0Njgz.YNL_7A.JMyT8TKKFmVbk1UmF56syW6Y1r0')
