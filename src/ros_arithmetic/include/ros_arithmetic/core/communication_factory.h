/****************************************************************************
* 		Copyright (C) 2017 by KPIT Technologies                     *
*                                                                           *
****************************************************************************/

/**
* @file      communication_factory.h
*
* @author    Sujeyendra Tummala (Tummala.Sujeyendra@kpit.com)
*
* @date      18-Oct- 2017
*
* @brief     This file declares the communication factory class 
*
**/

#ifndef COMMUNICATION_FACTORY_H
#define COMMUNICATION_FACTORY_H

/*! Include Files */
#include "ros_arithmetic/core/communication_interface.h"

/*! Class Declarations */
class CommFactory {
 public:
  /**
  * Function name: CommFactory
  *
  * @brief      Defines the constructor that initialises the comm interface
  *             object to NULL
  *
  * @param[in]  None
  *
  * @param[out] None
  *
  * @return     None
  *
  **/
  CommFactory();
 
  /**
  * Function name: ~CommFactory
  *
  * @brief      Implements the destructor that deletes the communication 
  *             interface object if existing and intializes it to NULL
  *
  * @param[in]  None
  *
  * @param[out] None
  *
  * @return     None
  *
  **/  
  ~CommFactory();
  
  /**
  * Function name: ~CommFactory
  *
  * @brief      Defines the functionality to delete the existing reference to 
  *             the the communication object and initialize to the received object
  *
  * @param[in]  CommunicationInterface* comm_int 
  *               Holds the communication interface object to be assigned
  *
  * @param[out] None
  *
  * @return     Void
  *
  **/
  void CreateCommunicator(CommunicationInterface* comm_int);
  
  /**
  * Function name: ExecuteCommunication
  *
  * @brief Execute communication to send message
  *
  * @param[in]	None
  *
  * @return	void
  **/
  void ExecuteCommunication();
  
 private:
  /** Holds the pointer to communication interface object */
  CommunicationInterface* communication_interface_;  
};
#endif
