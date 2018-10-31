/*
  class file for UtPod

*/

#include<iostream>
#include "UtPod.h"
#include "Song.h"

using namespace std;

  UtPod::UtPod()
  {
    memSize = MAX_MEMORY;  
  }

  UtPod::UtPod(int size)
  {
    if ( size > MAX_MEMORY || size <= 0 ){
      memSize = MAX_MEMORY;
    }else{
      memSize = size;
    }
  }

  int UtPod::addSong(Song const &s)
  {
    return SUCCESS;
    
  }
  
  int UtPod::removeSong(Song const &s)
  {
    return SUCCESS;

  }

  void UtPod::shuffle()
  {


  }

  void UtPod::showSongList()
  {



  }

  void UtPod::sortSongList()
  {
  
  
  }

  void UtPod::clearMemory()
  {


  }

  int UtPod::getRemainingMemory()
  {
    int remMem = 0;


    return remMem;
  }

  UtPod::~UtPod()
  {
    // cout << "In UtPod destructor" << endl;
  
  }