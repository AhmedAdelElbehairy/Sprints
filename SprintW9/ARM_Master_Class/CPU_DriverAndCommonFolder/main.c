#include "TM4C123GH6PM.h"
#include "CPU.h"

int main()
{
  CPU_SwitchToUserMode();
  CPU_SwitchToPrivilegedMode();
  return 0;
}
