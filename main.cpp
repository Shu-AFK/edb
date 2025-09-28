// https://tartanllama.xyz/posts/writing-a-linux-debugger/setup/

#include <iostream>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Program path was not specified";
    return -1;
  }

  auto prog = argv[1];

  auto pid = fork();
  // Child process
  if (pid == 0) {
    ptrace(PTRACE_TRACEME, 0, nullptr, nullptr);
    execl(prog, prog, nullptr);
  }

  // Parent process
  else if (pid >= 1) {
    
  }
}
