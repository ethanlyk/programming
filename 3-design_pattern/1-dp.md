### GoF 23-Design Pattern
* Design Pattern: 樣式是某外在背景環境(Context) 下﹐對特定問題(Problem)的慣用解決之道(Solution)    

* Creational: 如何有效率的產生、管理與操作物件
	* Abstract Factory: 它可以產生一系列的物件，維護同一系列物件之間的關係
	* Builder: 物件是由個別組件（Component）組合而成，個別組件建立非常複雜，但說明如何運用組件建立非 常簡單，您希望將建立複雜組件與運用組件方式分離，則可以使用Builder模式。
	* Factory: 在一個抽象類別中留下某個建立元件的抽象方法沒有實作，其它與元件操作相關聯的方法都先依賴於元件所定義的介面，而不是依賴於元件的實 現， 當您的成品中有一個或多個元件無法確定時，您先確定與這些元件的操作介面，然後用元件的抽象操作介面先完成其它的工作，元件的實作（實現）則推遲至實現元 件介面的子類完成，一旦元件加入，即可完成您的成品。
	* Prototype: 定義出一個prototype（原型），然後利用這個原型，來產生物件。產生的方式不同於Factory Pattern中使用的new，而是利用clone（複製）。
	* Singleton: 主要作用是保證在應用程式中，一個Class只有一個實例存在。
	* (Simple Fatory): 一個Simple Factory生產成品，而對客戶端隱藏產品產生的細節，物件如何生成，生成前是否與其它物件建立依賴關係，客戶端皆不用理會，用以將物件生成方式之變化 與客戶端程式碼隔離。
* Structural: 如何設計物件之間的靜態結構，如何完成物件之間的繼承、實現與依賴關係
	* Adapter: 主要目的便是藉由轉接方式，解決介面不同的問題。它的結構也很簡單，就是一頭接我們要的介面，另一頭接提供功能的元件，然後作對應。
	* Bridge: 将抽象部分与它的实现部分分离，使它们都可以独立地变化。 其精神在於降低abstraction和implementor之間的耦合度讓abstraction在延伸子類別時，不用擔心因為implementor的改變，而須修改子類別的程式碼。
	* Composite: 将对象组合成树形结构以表示“部分-整体”的层次结构。C o m p o s i t e 使得用户对单个对象和组合对象的使用具有一致性。
	* Decorator: 動態給一個物件添加一些額外的職責
	* Flyweight: 运用共享技术有效地支持大量细粒度的对象。
	* Facade: 爲子系統中的一組介面提供一個一致的介面
	* Proxy: 为其他对象提供一种代理以控制对这个对象的访问。
* Behavioral: 物件之間的互動行為，讓整個程式的動態結構（像是物件調度）更有彈性
	* Chain of responsibility: 使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。将这些对象连成一条链，并沿着这条链传递该请求，直到有一个对象处理它为止。
	* Command: 将一个请求封装为一个对象，从而使你可用不同的请求对客户进行参数化
	* Interpreter: 给定一个语言，定义它的文法的一种表示，并定义一个解释器，这个解释器使用该表示来解释语言中的句子。
	* Iterator: 逐一取得某物件內部的所有資料（或物件）
	* Mediator: 用一个中介对象来封装一系列的对象交互。中介者使各对象不需要显式地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。
	* Memoto: 在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。这样以后就可将该对象恢复到原先保存的状态。
	* State: 允许一个对象在其内部状态改变时改变它的行为。
	* Strategy: 定義一系列演算法，將每一個演算法封裝起來，可互換使用，更可以在不影響外界的情況下各別抽換所引用的演算法。
	* Observer: 定義一對多的物件依存關係，讓物件狀態一有變動，就自動通知其它相依物件作該作的更新動作。
	* Template: 定義好演算法的輪廓，某些步驟則留給子類別去填補，以便在不改變演算法整體架構的情況下讓子類別去精鍊某些步驟
	* Visitor: 表示一个作用于某对象结构中的各元素的操作。它使你可以在不改变各元素的类的前提下定义作用于这些元素的新操作。
