#include <stdio.h>
#include <string.h>

//Constants
#define MAX 5

//Structure
typedef struct
{
    int roomID;
    int status;
    char customerName[20]; 
}Room;

//Function Prototypes
void listOccupiedRooms();
void assignRoom();

//Global Variables
int Quit = 0;
int input;
Room RoomList[MAX];


int main()
{
    //generate hotel rooms
    for (int i = 0; i < MAX; i++)
    {
        RoomList[i].roomID = i + 1;
        RoomList[i].status = 0;
    }
    
    printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n");
    printf("1: listOccupiedRooms()\n");
    printf("2: assignRoom()\n");
    printf("3: removeRoom()\n");
    printf("4: findCustomer()\n");
    printf("5: quit\n");
    
    while (Quit == 0)
    {
        printf("Enter your choice:\n");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                listOccupiedRooms();
                break;
            case 2:
                assignRoom();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                Quit = 1;
                printf("Program Ended\n");
                break;
        }
    }
}


void listOccupiedRooms()
{
    int RoomNotEmpty = 0;
    printf("listOccupiedRooms(): \n");
    //no room is occupied
    for (int i = 0; i < MAX; i++)
    {
        if (RoomList[i].status == 1)
        {
            printf("RoomID: %d\n", RoomList[i].roomID);
            RoomNotEmpty = 1;
        }
    }
    if (RoomNotEmpty == 0)
    {
        printf("The hotel is empty\n");
    }
}

void assignRoom()
{
    int roomID, HotelFull = 1;
    int AskRoomID = 1;
    char str[20];
    printf("assignRoom():\n");

    for (int i = 0; i < MAX; i++)
    {
        if (RoomList[i].status != 1)
        {
            HotelFull = 0;
            break;
        }
    }
    
    if (HotelFull == 1)
    {
        printf("The hotel is full\n");
        return;
    }

    while(AskRoomID == 1)
    {
        printf("Select your RoomID (Between 1 to 5): ");
        scanf("%d", &roomID);
        fflush(stdin);
        //Checks range of roomID
        if (roomID < 1 || roomID > 5)
        {
            printf("Enter a roomID between 1 and 5\n");
            continue;
        }
        //check if roomID exists and not occupied
        for (int i = 0; i < MAX; i++)
        {
            if (roomID == RoomList[i].roomID && RoomList[i].status == 0)
            {
                //ask user to enter customerName
                printf("Enter customer name: ");
                fgets(str, 20, stdin);
                //copies string over to customer
                strcpy(RoomList[i].customerName,str);
                //Turn Off the Loop
                AskRoomID = 0;
                RoomList[i].status = 1;
                printf("The room has been assigned successfully \n");
            }
            else if (roomID == RoomList[i].roomID && RoomList[i].status == 1)
            {
                //Occupied Room
                printf("Occupied! Enter another roomID\n");
                //Quits for loop and asks for roomID
                break;
            }
        }
    }
}