Leetcode solutions


1. 3 main features of OOP is

Inheritance: Inheritances means containing a "is a" relationship between two classes. You put the same features among these derived classes into base class so that these common features could be share through inheritance.

Encapsulation: Encapsulation is the how you define the boundary of your class, data and methods. The four visibility modifiers are public, default(without any keywords), protected and private.

Polymorphism: Polymorphism means a variable of a super type can refer to a subtype object. For example, Automobile is the base case of Bus, Truck. However, the way to drive a Bus and a Truck may be slightly different so that the implementation of this drive() method is different. With polymorphism, you can instantiate objects with all the same declared type Automobile but different actual type (Bus, Truck etc,...) so that you can call the same method drive() with different implementations without checking the type of the object.

2. Design an online hotel booking system
We have to design an online hotel booking system where a user can search a hotel in a given city and book it.

My Solution :

'
Main Classes :

    User
    Room
    Hotel
    Booking
    Adress

Enums :

public enum RoomStatus {
    EMPTY
    NOT_EMPTY;
}

public enum RoomType{
    SINGLE,
    DOUBLE,
    TRIPLE;
}

public enum PaymentStatus {
    PAID,
    UNPAID;
}

class User{

int userId;
String name;
Date dateOfBirth;
String mobNo;
String emailId;
String sex;
}

// For the room in any hotel
class Room{

int roomId;
int hotelId;
RoomType roomType;
RoomStatus roomStatus;
}

class Hotel{

int hotelId;
String hotelName;
Adress adress;
List<Room> rooms; // hotel contains the list of rooms
float rating;
Facilities facilities;
}

// a new booking is created for each booking done by any user
class Booking{
    int bookingId;
    int userId;
    int hotelId; 
    List<Rooms> bookedRooms; 
    int amount;
    PaymentStatus status_of_payment;
    Time bookingTime;
    Duration duration;
}

class Adress{

string city;
string pinCode;
string streetNo;
string landmark;
}

class Duration{

Time from;
Tiime to;
}

class Facilities{

bool provides_lift;
bool provides_power_backup;
bool provides_hot_water;
bool provides_breakfast_free;
}
'

