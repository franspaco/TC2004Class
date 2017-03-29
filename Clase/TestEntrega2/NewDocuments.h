/*
 * NEW DOCUMENT TYPES SHOULD BE ADDED HERE
 *
 * Example:
 *
 *  class <NAME> : public Documents {
 *  public:
 *    <NAME>(){
 *      name = "<NAME>";
 *    }
 *  };
 *
 * Must implement a constructor to give it a name!
 *
 */

 class Poster : public Documents {
 public:
   Poster(){
     name = "Poster";
   }
 };

 class Flyer : public Documents {
 public:
   Flyer(){
     name = "Flyer";
   }
 };
