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
    songs = NULL;
  }

  UtPod::UtPod(int size)
  {
    if ( size > MAX_MEMORY || size <= 0 ){
      memSize = MAX_MEMORY;
    }else{
      memSize = size;
    }
    songs = NULL;
  }

  int UtPod::addSong(Song const &s)
  {
    if ((s.getSize() <= 0) || (s.getArtist() == "") || (s.getTitle() == "")){
      return NO_MEMORY;
    }
    if (s.getSize() > this->getRemainingMemory()){
      return NO_MEMORY;
    }
    SongNode *addSong = new SongNode;
    addSong->s = s;
    addSong->next = songs;
    songs = addSong;
    return SUCCESS;
  }
  
  int UtPod::removeSong(Song const &s)
  {
    if (songs == NULL){
      return NOT_FOUND;
    }else{
      SongNode *tempSong = songs;
      if (tempSong->s == s){
        songs = song->next;
        delete tempSong;
        return SUCCESS
      }
    }
    while((tempSong != NULL) && (tempSong->next != NULL)){
      if (tempSong->next->s == s){
        SongNode *deleteSong = tempSong->next;
        tempSong->next = deleteSong->next;
        delete deleteSong;
        return SUCCESS:
      }
      tempSong = tempSong->next;
    }
    return NOT_FOUND:
  }

  void UtPod::shuffle()
  {


  }

  void UtPod::showSongList()
  {
    SongNode *tempNode = songs;
    while(tempNode != NULL){
      cout << (tempNode->s).getTitle() << ", " << (tempNode->s).getArtist() << ", " << (tempNode->s).getSize() << endl;
      tempNode = tempNode->next;
    }
  }

  void UtPod::sortSongList()
  {
  
  
  }

  void UtPod::clearMemory()
  {
    SongNode *tempNode = songs;
    if (tempNode == NULL){
      return;
    }
    while (tempNode->next != NULL){
      songs = songs->next;
      delete tempNode;
      tempNode = songs;
    }
    delete tempNode;
  }

  int UtPod::getRemainingMemory()
  {
    int remMem = 0;
    SongNode *tempNode = songs;
    while (tempNode != NULL){
      remMem -=(tempNode->s).getSize();
      tempNode = tempNode->next;
    }
    return remMem;
  }

  UtPod::~UtPod()
  {
    // cout << "In UtPod destructor" << endl;
    this->clearMemory();
  }
