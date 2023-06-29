/*
 * MQTT.c
 *
 *  Created on: Jun 24, 2023
 *      Author: Osama
 */

#include "MQTT.h"

extern UART_HandleTypeDef huart6;

uint8_t Packet[200] = {0};
uint8_t Packet_Idx = 0;

uint16_t Packet_Id = 1;

char *protocol_name = "MQTT";

void MQTT_Connect(uint8_t* clientID) {

	uint8_t remLen = 12 + strlen(clientID);
	// encode packet

	Packet_Idx = 0;
	Packet[Packet_Idx++] = 0x10;       // connect type
	Packet[Packet_Idx++] = remLen;     // remaining length

	Packet[Packet_Idx++] = 0x00;
	Packet[Packet_Idx++] = strlen(protocol_name);
	strcpy(&Packet[Packet_Idx] , protocol_name);
	Packet_Idx += strlen(protocol_name);

	Packet[Packet_Idx++] = 0x04;         // version
	Packet[Packet_Idx++] = 0x02;         // clean session only
	Packet[Packet_Idx++] = 0xFF;
	Packet[Packet_Idx++] = 0xFF;

	Packet[Packet_Idx++] = 0x00;
	Packet[Packet_Idx++] = strlen(clientID);
	strcpy(&Packet[Packet_Idx] , clientID);
	Packet_Idx += strlen(clientID);

	//  send packet
	HAL_UART_Transmit(&huart6, Packet, Packet_Idx, Packet_Idx*2);
}
void MQTT_Publish(uint8_t* topic , uint8_t* msg , uint32_t len, uint8_t QoS) {

	uint8_t msg_it = 0;
	uint8_t remLen = 12 + strlen(topic) + len;
	// encode packet
	Packet_Idx = 0;

	if(QoS > 0){
		remLen += 2;
		Packet[Packet_Idx++] = 0x32;       //QoS1
	}
	else{
		Packet[Packet_Idx++] = 0x30;       //QoS0
	}

    Packet[Packet_Idx++] = remLen;

	Packet[Packet_Idx++] = 0x00;
	Packet[Packet_Idx++] = strlen(topic);
	strcpy(&Packet[Packet_Idx] , topic);
	Packet_Idx += strlen(topic);

	if(QoS > 0){
		Packet[Packet_Idx++] = (uint8_t)(Packet_Id >> 8);
		Packet[Packet_Idx++] = (uint8_t)(Packet_Id);
		Packet_Id++;
	}

	for(msg_it=0; msg_it<len; ++msg_it){
		Packet[Packet_Idx++] = msg[msg_it];
	}

	//  send packet
	HAL_UART_Transmit(&huart6, Packet, Packet_Idx, Packet_Idx*2);
}
void MQTT_Subscribe(uint8_t* topic) {

	uint8_t remLen = 5 + strlen(topic);
	// encode packet
	Packet_Idx = 0;

	Packet[Packet_Idx++] = 0x82;       // connect type
	Packet[Packet_Idx++] = remLen;     // remaining length
	Packet[Packet_Idx++] = (uint8_t)(Packet_Id >> 8);
	Packet[Packet_Idx++] = (uint8_t)(Packet_Id);
	Packet_Id++;

	Packet[Packet_Idx++] = 0x00;
	Packet[Packet_Idx++] = strlen(topic);
	strcpy(&Packet[Packet_Idx] , topic);
	Packet_Idx += strlen(topic);

	Packet[Packet_Idx++] = 0x01;

	//  send packet
	HAL_UART_Transmit(&huart6, Packet, Packet_Idx, Packet_Idx*2);
}


