#include <stdio.h>

class CPU {
public:
	void Boot() {
		printf("CPU::Boot()\n");
	}

	void Execute() {
		printf("CPU:Execute()\n");
	}
};

class Memory {
public:
	void Load() {
		printf("Memory::Load()\n");
	}
};

class HardDrive {
public:
	void Read() {
		printf("HardDrive::Read()\n");
	}
};

/*
 * Facade
 */
class Computer {
public:
	void Start() {
		m_cpu.Boot();
		m_memory.Load();
		m_harddrive.Read();
		m_cpu.Execute();
	}

private:
	CPU m_cpu;
	Memory m_memory;
	HardDrive m_harddrive;
};

int main() {
	Computer computer;
	computer.Start();
}
