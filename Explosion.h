#ifndef EXPLSION_H
#define EXPLSION_H

#include "Object.h"

class Explosion : public Object
{
private:
   int frame;
   SDL_Rect clip[NUM_OF_FRAME];
public:
   Explosion( SDL_Renderer*, string path );

   ~Explosion()
   {

   }

   void set_clip();

   void set_frame( const int& _frame ) ;

   void showEx( SDL_Renderer* renderer );
};
#endif // EXPLSION_H
