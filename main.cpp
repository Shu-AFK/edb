// https://tartanllama.xyz/posts/writing-a-linux-debugger/setup/

#include <iostream>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

#include "debugger.h"

void execute_debugee(const std::string &prog_name) {
  if (ptrace(PTRACE_TRACEME, 0, nullptr, nullptr) < 0) {
    std::cerr << "Error in ptrace\n";
    return;
  }
  execl(prog_name.c_str(), prog_name.c_str(), nullptr);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Program path was not specified";
    return -1;
  }

  auto prog = argv[1];

  auto pid = fork();
  // Child process
  if (pid == 0) {
    execute_debugee(prog);
  }

  // Parent process
  else if (pid >= 1) {
    std::cout << "Starting debugging process " << pid << std::endl;
    edb::debugger dbg{prog, pid};
    dbg.run();
  }
}
