#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "contact.h"

void initialize(AddressBook *addressBook)
{

    FILE *fp = fopen("contacts.txt", "r");
    addressBook->contactCount=0;

    if(fp == NULL)
    {
        printf("File is not open\n");
        return;
    }

    int i=0;

    while(fscanf(fp, "%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email) == 3)
    {
    
        i++; 
        addressBook->contactCount++; //increment count;
    }

    fclose(fp);
}

//initialize
    /*
        1.open contact.txt file in read mode
        addressBook->contactCount = 0
        2.run a loop until reaching EOF
            {
                1.read name from file and store to addressBook->contacts[i].name
                2.read phone from file and store to addressBook->
                3.read mail from file and ""
                4. inc addressBook->contactCount++
            }
        3.close file
    */    




void listContacts(AddressBook *addressBook)
{
    if(addressBook->contactCount == 0)
    {
        printf("No contacts found\n");
        return;
    }

    printf("----------------------------------------------------------------");
    printf("\nSI no.     Name              Phone                 Email\n");
    printf("-----------------------------------------------------------------\n");

    for(int i=0; i < addressBook->contactCount; i++)
    {
    printf("%-10d %-15s %-20s %s\n",
            i+1, 
            addressBook->contacts[i].name, 
            addressBook->contacts[i].phone, 
            addressBook->contacts[i].email); // print all the contacts present in the txt file.
    }

}





void createContact(AddressBook *addressBook)
{

    char temp_name[30];
    char temp_phone[15];
    char temp_email[30];

    int valid;
    int count=0;
    int i, j;
    
    while(count < 3) // give 3 chances
    {
    
        printf("Enter the name: ");
        scanf(" %[^\n]", temp_name);

        valid =1;
        i=0;

        if(!(temp_name[0] >= 'A' && temp_name[0] <= 'Z')) //check if string 0 index not contains uppercase give valid 0.
        {
            valid =0;
        }

        while(temp_name[i] != 0)
        {
            if(!((temp_name[i] >= 'A' && temp_name[i] <= 'Z') || (temp_name[i] >= 'a' && temp_name[i] <= 'z') || temp_name[i] == ' '))
            {
                valid=0;
                break;
            }

            i++;
        }
        

        for(int i = 0; temp_name[i]!=0; i++)
        {
            if(temp_name[i]== ' '  && temp_name[i+1] == ' ')
            {
                valid=0;
                break;
            }
        }
         
        if(valid == 1)
        {
            break;
        }
        else
        {
            printf("Invalid Name try again.\n");
             count++;
        }
       

        if(count ==3)
        {
            printf("Too many invalid attempts.\n");
            return;
        }
     
    }

    
    count =0;
    while(count < 3)
    {
        printf("Enter the phone number: ");
        scanf(" %[^\n]", temp_phone);

        valid = 1;
        
        if (strlen(temp_phone) !=10)
        {
            valid =0;
        }

        for(i =0; temp_phone[i] != 0; i++)
        {
            if(temp_phone[i] < '0' || temp_phone[i] > '9')
            {
                valid =0;
                break;
            }
        }

        if(valid == 1)
        {
            break;
        }
        else
        {
            printf("Invalid phone entered try again\n");
            count++;
        }
        


        if(count ==3)
        {
            printf("Too many invalid input attempted\n");
            return;
        }
    }

    count=0;
    while(count < 3)
    {
        printf("Enter the email id: ");
        scanf(" %[^\n]", temp_email);

        valid =1;
        int at =0;
        int i;

        for(int i =0; temp_email[i] !=0; i++)
        {
            if(temp_email[i] >= 'A' && temp_email[i] <= 'Z')
            {
                valid =0;
                break;
            }
        }

        for(int i =0; temp_email[i] != 0; i++)
        {
            if(temp_email[i] == '@')
            {
                at =1;

                if(!(temp_email[i] == '@' && (temp_email[i+1] >= 'a' && temp_email[i+1] <= 'z')))
                {
                    valid =0;
                }
                break;
            }
        }

        if(at == 0)
        {
            valid =0;
        }

        if(!strstr(temp_email, ".com"))
        {
            valid = 0;
        }

        if(valid)
        {
            break;
        }
        else
        {
            printf("Invalid email try again\n");
            count++;
        }

    }

    if(count == 3)
    {
        printf("Too many invalid attempts \n");
        return;
    }

        strcpy(addressBook->contacts[addressBook->contactCount].name, temp_name);
        strcpy(addressBook->contacts[addressBook->contactCount].phone, temp_phone);
        strcpy(addressBook->contacts[addressBook->contactCount].email, temp_email);

        addressBook->contactCount++;
        printf("Contact added successfully!\n");
    
}

    /*
        1.read name char temp_name[30];
        2.check name has only 'A' - 'Z' or 'a' - 'z' or ' '
        invalid no-> count chance
            go to step no. 1
        valid yes->
        3.read phone char temp_phone[15];
        4.check strlen = 10, all are '0' - '9'
        invalid no-> count chance
            go to step 3
        valid yes ->
        5.read mail char temp-mail[30];
        6.check '@' present, ".com", all are lower case, after @ there should be min 1 char present
        invalid no-> count chance
            go to step 5
        valid yes->
        7. store temp_name, temp_phone, temp_mail to addressBook->contacts[addressBook-<conatctCount]
        8. inc contactCount
        9. stop
        10. search for it if it is present tell it present
    */


void searchContact(AddressBook *addressBook)
{
    char temp_name[30];
    char temp_phone[15];
    char temp_email[30];
    int choice;

    printf("Select from the menu: \n");
    printf("1.Search with name\n");
    printf("2.Search with Phone number\n");
    printf("3.Search with email\n");
    printf("Enter the choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    //searchbyname(AddressBook *addressBook)
        
        printf("Enter the name: \n");
        scanf("%s", temp_name);

        
        int flag =0;
        for(int i=0; i<addressBook->contactCount; i++)
        {
            if(strstr(addressBook->contacts[i].name,temp_name)!= NULL)
            {
                flag =1;
                printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }

        }

        if(flag ==0)
        {
            printf("User not found!\n");
            return;
        }
        break;

    case 2:
    //searchbyphone(AddressBook *addressBook)
        
        printf("Enter the phone:  \n");
        scanf("%s", temp_phone);

        for(int i=0; i<addressBook->contactCount; i++)
        {
            if(strstr(addressBook->contacts[i].phone ,temp_phone) != NULL)
            {
                flag =1;
                printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }

        }

        if(flag ==0)
        {
            printf("User not found!\n");
            return;
        }
        break;

    case 3:
    //searchbyemail(AddressBook *addressBook)
        
        printf("Enter the email: \n");
        scanf("%s", temp_email);

        for(int i=0; i<addressBook->contactCount; i++)
        {
            if(strstr(addressBook->contacts[i].email ,temp_email) != NULL)
            {
                flag=1;
                printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }

        }

        if(flag ==0)
        {
            printf("User not found!\n");
            return;
        }
        break;

    default:
        break;
    }
    
}

    /*
    1.Ask user based on what to seacrh
        1.name
        2.phone
        3.mail
    2.read option
    3. switch (option)
        case 1: //search based on name
        {
            1.read name            
            2.search strcmp(temp_name, addressBook->contacts[i].name)
                loop from 0 to contactCount-1
                1.fetch addressBook[i]
                2.strstr(find substring name is found)
                yes-> print contact detail of all
                no->go with next iteration
        }
        case 2:// search based on phone
        {
            1.read phone or digit
            2.search strcmp(temp_name, addressBook->contacts[i].phone)
                loop from 0 to contactCount-1
                1.fetch addressBook[i]
                2.strstr(find substring name is found)
                yes-> print contact detail of all
                no->go with next iteration
        }
        
        case 3: // search based on email
        {
            1.read email or char
            2.search strcmp(temp_name, addressBook->contacts[i].phone)
                loop from 0 to contactCount-1
                1.fetch addressBook[i]
                2.strstr(find substring name is found)
                yes-> print contact detail of all
                no->go with next iteration
        }
    */

void editContact(AddressBook *addressBook)
{

    char temp_name[30];
    char temp_phone[15];
    char temp_email[30];

    int flag, i;
    int foundindex;
    int valid, namecount, phonecount, emailcount;
    int count=0;

    for(count = 0; count < 3; count++)
    {
        flag =0;

        printf("1.Edit the name\n");
        scanf(" %[^\n]", temp_name);

        for(int i=0; i<addressBook->contactCount; i++)
        {
            if(strstr(addressBook->contacts[i].name ,temp_name) != NULL)
            {
                foundindex = i; // when index is found put that index in foundindex
                flag=1;

                printf("Found Contacts: \n");
                printf("%d %s %s %s\n",i+1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                break;
            }
           
        }

        if(flag == 1)
        {
            break;
        }
        else
        {
            printf("Entered name not found Try again!\n");
        }
    }

    if(count  == 3)
    {
        printf("Contact is not found!");
        return;
    }

    namecount=0;
    while(namecount < 3)
    {
    
        printf("Enter the name: ");
        scanf(" %[^\n]", temp_name);

        valid =1;
        i=0;

        if(!(temp_name[0] >= 'A' && temp_name[0] <= 'Z'))
        {
            valid =0;
        }

        while(temp_name[i] != 0)
        {
            if(!((temp_name[i] >= 'A' && temp_name[i] <= 'Z') || (temp_name[i] >= 'a' && temp_name[i] <= 'z') || temp_name[i] == ' '))
            {
                valid=0;
                break;
            }

            i++;
        }
        

        for(int i = 0; temp_name[i]!=0; i++)
        {
            if(temp_name[i]== ' '&& temp_name[i+1] == ' ')
            {
                valid=0;
                break;
            }
        }
         
        if(valid == 1)
        {
            break;
        }
        else
        {
            printf("Invalid Name try again.\n");
             namecount++;
        }
       

        if(namecount == 3)
        {
            printf("Too many invalid attempts.\n");
            return;
        }
     
    }

    
    phonecount =0;
    while(phonecount < 3)
    {
        printf("Enter the phone number: ");
        scanf(" %[^\n]", temp_phone);

        valid = 1;
        
        if (strlen(temp_phone) !=10)
        {
            valid =0;
        }

        for(i =0; temp_phone[i] != 0; i++)
        {
            if(temp_phone[i] < '0' || temp_phone[i] > '9')
            {
                valid =0;
                break;
            }
        }

        if(valid == 1)
        {
            break;
        }
        else{
            printf("Invalid phone entered try again\n");
            phonecount++;
        }
        

        if(phonecount == 3)
        {
            printf("Too many invalid input attempted\n");
            return;
        }
    }


    count=0;
    while(count < 3)
    {
        printf("Enter the email id: ");
        scanf(" %[^\n]", temp_email);

        valid =1;
        int at =0;
        int i;

        for(int i =0; temp_email[i] !=0; i++)
        {
            if(temp_email[i] >= 'A' && temp_email[i] <= 'Z')
            {
                valid =0;
                break;
            }
        }

        for(int i =0; temp_email[i] != 0; i++)
        {
            if(temp_email[i] == '@')
            {
                at =1;

                if(!(temp_email[i] == '@' && (temp_email[i+1] >= 'a' && temp_email[i+1] <= 'z')))
                {
                    valid =0;
                }
                break;
            }
        }

        if(at == 0)
        {
            valid =0;
        }

        if(! strstr(temp_email, ".com"))
        {
            valid = 0;
        }

        if(valid)
        {
            break;
        }
        else
        {
            printf("Invalid email try again\n");
            count++;
        }

    }

    if(count == 3)
    {
        printf("Too many invalid attempts \n");
        return;
    }


        strcpy(addressBook->contacts[foundindex].name, temp_name);
        strcpy(addressBook->contacts[foundindex].phone, temp_phone);
        strcpy(addressBook->contacts[foundindex].email, temp_email);

        printf("Contact edited successfully!\n");

}

    //EditContact
    /*
        1. read the name
        2. find name is present 
            if no-> give 3 chance go step 1
            if yes-> //edit
                    1. read name -> validate
                    2. read phone -> validate
                    3. read email -> validate
                    4. check that i/p already existing
                        yes-> stop
                        no-> use strcpy() to copy to addressbook
        3. Stop

    */


void deleteContact( AddressBook *addressBook)
{

    char temp_name[30];
    int flag, i;
    int foundindex;
    
    int count=0;

    for(count = 0; count < 3; count++)
    {
        flag =0;

        printf("1.Enter the name\n");
        scanf(" %[^\n]", temp_name);

        for(int i=0; i<addressBook->contactCount; i++)
        {
            if(strcmp(addressBook->contacts[i].name ,temp_name) == 0) 
            {
                flag=1;
                foundindex = i;
               
                printf("Found Contacts: \n");
                printf("%d %s %s %s\n",i+1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                
                break;
            }
           
        }

        if(flag == 1)
        {
            
            for(int j = foundindex; j < addressBook->contactCount-1; j++)
            {
                strcpy(addressBook->contacts[j].name, addressBook->contacts[j+1].name);
                strcpy(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone);
                strcpy(addressBook->contacts[j].email, addressBook->contacts[j+1].email);
            }

            addressBook->contactCount--;
            printf("Deleted successfully!\n");

            for(i =0; i<addressBook->contactCount; i++)
            {
                printf("%d %s %s %s\n",i+1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }

            return;
        }
        else
        {
            printf("Entered name not found Try again!\n");
        }
    }

    if(count  == 3)
    {
        printf("Contact is not found!");
        return;
    }
}


//DeleteContact
    /*
    1.read name
    2.find the name is present or not .
    No-> 3 chance
    yes-> run a loop (i = index where contact is found to delete) to contactCount -1
    {
        strcpy(AddressBook->contacts[j].name, contacts[j+1].name)
        strcpy(AddressBook->contacts[j].name, contacts[j+1].phone)
        strcpy(AddressBook->contacts[j].name, contacts[j+1].email)
    }

    dec contactCount by 1;
    contactCount-1;
    
    */


void savecontacts(AddressBook *addressBook)
{
    FILE *fptr = fopen("contacts.txt", "w");

    if(fptr == NULL)
    {
        printf("File is not open\n");
        return;
    }


    for(int i=0; i< addressBook->contactCount; i++)
    {
        fprintf(fptr, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    fclose(fptr);
    printf("Contact saved successfully!\n");

}

//SaveContacts
    /*
    1.Open contact.txt write mode
    2.Run a loop contactCount times
    {
        1.read name from addressbook, write it to file
        2.Write ','
        3.Read phone from addressBook write it to file
        4.Wtite ','
        5.Read email from addressBook write it to file
        6.write '\n'
    }
    3.close file
    4.stop
    */


    

