
class CPU {
	public void Boot() {
		System.out.println("CPU::Boot()");
	}

	public void Execute() {
		System.out.println("CPU::Execute()");
	}
}

class Memory {
	public void Load() {
		System.out.println("Memory::Load()");
	}
}

class HardDrive {
	public void Read() {
		System.out.println("HardDrive::Read()");
	}
}

/*
 * Facade
 */
class Computer {
	private CPU m_cpu;
	private Memory m_memory;
	private HardDrive m_harddrive;

	public Computer() {
		m_cpu = new CPU();
		m_memory = new Memory();
		m_harddrive = new HardDrive();
	}

	public void Start() {
		m_cpu.Boot();
		m_memory.Load();
		m_harddrive.Read();
		m_cpu.Execute();
	}
}

public class Sample {
	public static void main(String[] args) {
		Computer computer = new Computer();
		computer.Start();
	}
}
