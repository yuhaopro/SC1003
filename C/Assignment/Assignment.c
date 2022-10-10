#include <stdio.h>

#define MAX 5

typedef struct
{
    int roomID;
    int status;
    char customerName[20]; 
}Room;

void listOccupiedRooms(Room* Roomlist, int size);


int main()
{
    int Quit = 0;
    int input;
    Room RoomList[MAX];
    RoomList[0].status = 1;
    RoomList[0].roomID = 0;
    
    while (Quit == 0)
    {
        printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n");
        printf("1: listOccupiedRooms()\n");
        printf("2: assignRoom()\n");
        printf("3: removeRoom()\n");
        printf("4: findCustomer()\n");
        printf("5: quit\n");
        
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                listOccupiedRooms(RoomList, 1);
                break;
            case 2:
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


void listOccupiedRooms(Room* Roomlist, int size)
{
    int RoomNotEmpty = 0;
    printf("listOccupiedRooms(): \n");
    //no room is occupied
    for (int i = 0; i < size; i++)
    {
        Room* temp = (Roomlist + i*sizeof(Room));
        if (temp->status == 1)
        {
            printf("RoomID: %d\n", temp->roomID);
            RoomNotEmpty = 1;
        }
    }
    if (RoomNotEmpty == 0)
    {
        printf("The hotel is empty\n");
    }
}