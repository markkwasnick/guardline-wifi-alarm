# guardline-wifi-alarm

Connects a Particle Photon to Guardline wireless driveway alarm receiver to publish events (for SMS, etc) via wifi. There did not seem to be any existing solution for this, so I created a quick one. Once you're publishing events to Particle.io, the possibilites become wide open. I integrated with Twilio to send SMS messages via a Webhook, which I will describe.

## What does it do?

When a sensor is tripped, an event will be published to particle.io named `SENSOR_TRIGGERED` with a date/time string. The D7 LED (on board) will also turn on and the program will wait for 1 second before allowing itself to fire again. You can then use pretty much any [webhook](https://docs.particle.io/guide/tools-and-features/webhooks/) or integration such as [IFTTT](https://docs.particle.io/guide/tools-and-features/ifttt/).

## Equipment

[Guardline driveway sensor and receiver](https://www.guardlinesecurity.com/collections/wireless-driveway-alarms/products/guardline-500-ft-wireless-driveway-alarm-w-lifetime-warranty)

[Particle Photon](https://store.particle.io/products/photon)

A breadboard, wiring shield or whatever you want to build the [circuit](#circuit).

## Setup

Pair the sensor to receiver and ensure it works. On the receiver, remove the battery cover and set dip switches 9,10,11,12 to ON. This will enable NO/NC for all zones.

Get your photon updated to at least firmware 0.6.3 (this is what I tested, slightly older may also work fine, just ensure Particle.publish API is there) and connected to wifi.

Setup circuit on breadboard or whatever you're using.

Use the Particle IDE to verify and then flash the code to Photon.

You can test without the receiver by connecting the line which should go to NO to the GND.

## Twilio

Prereq: [You will need a Twilio account that is setup](https://support.twilio.com/hc/en-us/articles/223136207-Getting-started-with-your-new-Twilio-phone-number)

You'll need to setup a Webhook integration on the [Particle console](https://console.particle.io/integrations). 

An example of mine is below with some notes.

![Twilio webhook example](https://raw.githubusercontent.com/markkwasnick/guardline-wifi-alarm/master/driveway-alarm-twilio-rev-1.png)

## Circuit

![Driveway alarm circuit](https://github.com/markkwasnick/guardline-wifi-alarm/blob/master/driveway-alarm-circuit-rev-1.PNG)
