#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define nameSize 50
#define userFile "Users.txt"

typedef struct{
    int id;
    char name[nameSize];
    int age;
} User;

int getInt(const char *msg) {
    int value;
    printf("%s", msg);
    if (scanf("%d", &value) != 1) {
        printf("Invalid Input\n");
        exit(1);
    }
    return value;
}

void getString(const char *msg, char *output, int maxLength) {
    printf("%s", msg);
    getchar();
    if (fgets(output, maxLength, stdin) == NULL) {
        printf("Invalid input \n");
        exit(1);
    }
    output[strcspn(output, "\n")] = 0;
}

void delete(){
int id = getInt("Enter User ID to delete: ");
    FILE *file = fopen(userFile, "r+");
    if (!file) {
        printf("No data available for deletion.\n");
        return;
    }
    User user;
    int found = 0;
    long delete_position = -1;
    while (fscanf(file, "%d, %49[^,], %d\n", &user.id, user.name, &user.age) == 3) {
        if (user.id == id) {
            found = 1;
            delete_position = ftell(file);
            break;
        }
    }

    if (found) {
        fseek(file, delete_position - (sizeof(user.id) + strlen(user.name) + sizeof(user.age) + 4), SEEK_SET);
        User next_user;
        while (fscanf(file, "%d, %49[^,], %d\n", &next_user.id, next_user.name, &next_user.age) == 3) {
            fprintf(file, "%d, %s, %d\n", next_user.id, next_user.name, next_user.age);
        }
        printf("User deleted successfully.\n");
    } else {
        printf("User ID not found.\n");
    }

    fclose(file);
}
void update(){
    int id = getInt("Enter User ID to update: ");
    FILE *file = fopen(userFile, "r+");
    if (!file) {
        printf("No data available for update.\n");
        return;
    }
    User u;
    int found = 0;
    fseek(file, 0, SEEK_SET);
    long file_size = 0;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    User *users = (User*)malloc(file_size);
    int userCount = 0;
    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%d, %49[^,], %d\n", &u.id, u.name, &u.age) == 3) {
        users[userCount++] = u;
    }
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            found = 1;
            getString("Enter new Name: ", users[i].name, nameSize);
            users[i].age = getInt("Enter new Age: ");
            break;
        }
    }

    
    if (found) {
        fseek(file, 0, SEEK_SET);
        for (int i = 0; i < userCount; i++) {
            fprintf(file, "%d, %s, %d\n", users[i].id, users[i].name, users[i].age);
        }
        printf("User updated successfully.\n");
    } else {
        printf("User ID not found.\n");
    }
    free(users);
    fclose(file);
}

int uniqueId(int id){
    FILE *file = fopen(userFile, "r");
    if(!file)
        return 1;
    
    User u;
    while(fscanf(file, "%d, %49[^,], %d \n", &u.id, &u.name, &u.age) == 3){
        if (u.id == id) {
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return 1;
}

void display(){
    FILE *file = fopen(userFile, "r");
    if (!file) {
        printf("Nothing found.\n");
        return;
    }
    User u;
    int count = 0;
    while (fscanf(file, "%d, %49[^,], %d\n", &u.id, u.name, &u.age) == 3) {
        printf("ID: %d, Name: %s, Age: %d\n", u.id, u.name, u.age);
        count++;
    }

    if (count == 0) {
        printf("No data available.\n");
    }else{
        printf("\nThese %d users are found here...\n\n", count);
    }

    fclose(file);
}

void add(){
    User u;
    u.id = getInt("Enter User ID: ");

    if(!uniqueId(u.id)){
        printf("User Id already exists.\n");
        return;
    }

    getString("Enter Name: ", u.name, nameSize);
    u.age = getInt("Enter age: ");

    FILE *file= fopen(userFile, "a");
    if(!file){
        printf("Can't open file");
        return;
    }

    fprintf(file, "\n%d, %s, %d\n", u.id, u.name, u.age);
    fclose(file);
    printf("User added \n");
}


void createFile(){
    FILE *file = fopen(userFile, "a");
    if(file==NULL){
        printf("Cant open file");
        exit(1);
    }
    fclose(file);
}

int main(){
    createFile();
    int option;
    while(1){
        printf("1. Add User\n");
        printf("2. Delete User\n");
        printf("3. Display Users\n");
        printf("4. Update User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        option = getInt("");

        switch(option){
            case 1:
                add();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                update();
                break;
            case 5:
                printf("\n-EXITED-\n");
                exit(0);
            default:
                printf("Enter valid input \n");
                exit(1);
        }
    }
    return 0;
}