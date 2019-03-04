/****************************************************************************
* 		Copyright (C) 2017 by KPIT Technologies                     *
*                                                                           *
****************************************************************************/

/**
* @file      communication_interface.h
*
* @author    Sujeyendra Tummala (Tummala.Sujeyendra@kpit.com)
*
* @date      18-Oct- 2017
*
* @brief     This file declares the communication Interface class 
*
**/

#ifndef COMMUNICATION_INTERFACE_H
#define COMMUNICATION_INTERFACE_H

/* Class Declarations */
class CommunicationInterface {
 public:   
  /**
  * Function name: SendMessage
  *
  * @brief      Defines the pure virtual function to implement the 
  *             functionality to send the message
  *
  * @param[in]  None
  *
  * @param[out] None
  *
  * @return     Void
  *
  **/
  virtual void SendMessage() = 0;
  
  /**
  * Function name: ReceiveMessage
  *
  * @brief      Defines the pure virtual function to implement the 
  *             functionality to receive the message
  *
  * @param[in]  None
  *
  * @param[out] None
  *
  * @return     Void
  *
  **/
  virtual void ReceiveMessage() = 0;
};

#endif
