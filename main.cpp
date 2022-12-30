#include <unistd.h>
#include <wait.h>
int main()
{
    int id = fork();
    if (!id)
    {
        while (1);
    }
    wait(NULL);
}