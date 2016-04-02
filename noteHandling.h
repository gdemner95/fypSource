/*
  ==============================================================================

    noteHandling.h
    Created: 1 Apr 2016 4:05:53pm
    Author:  George Demner

  ==============================================================================
*/

#ifndef NOTEHANDLING_H_INCLUDED
#define NOTEHANDLING_H_INCLUDED
class noteHandler
{
public:
    //create the list of notes
    noteHandler(){
        for (int i = 47; i < 70; i++){
            noteIDArray.add(i);
            playCount.add(0);
        }
    }
    ~noteHandler(){ }
void increment(int noteID){
    int index = noteIDArray.indexOf(noteID);
    playCount.set(index, playCount[index] + 1);
    
}
void decrement(int noteID){
    
    
}
void notePlaying(){
    
}
private:
Array<int> noteIDArray;
Array<int> playCount;

};
#endif  // NOTEHANDLING_H_INCLUDED
