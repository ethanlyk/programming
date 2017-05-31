
class Document {
	private boolean m_bSuccess;
	private int m_iData;
	private String m_strName;

	public Document(int iData, String strName) {
		m_iData = iData;
		m_strName = strName;
	}

	public String GetName() {
		return m_strName;
	}

	public int GetData() {
		return m_iData;
	}

	public boolean IsSuccess() {
		return m_bSuccess;
	}

	public void SetSuccess(boolean bSuccess) {
		m_bSuccess = bSuccess;
	}
}

/*
 * Handler
 */
interface IFormat {
	Document HandleRequest(int i);
}

class EnlargeFont implements IFormat {
	public Document HandleRequest(int iRequest) {
		System.out.println("Trying EnlargeFont");
		Document doc = new Document(1, "EnlargeFont");
		doc.SetSuccess(doc.GetData() == iRequest);
		return doc;
	}
}

class ChangeColor implements IFormat {
	public Document HandleRequest(int iRequest) {
		System.out.println("Trying ChangeColor");
		Document doc = new Document(2, "ChangeColor");
		doc.SetSuccess(doc.GetData() == iRequest);
		return doc;
	}
}

class AddHeader implements IFormat {
	public Document HandleRequest(int iRequest) {
		System.out.println("Trying AddHeader");
		Document doc = new Document(3, "AddHeader");
		doc.SetSuccess(doc.GetData() == iRequest);
		return doc;
	}
}

class AddFooter implements IFormat {
	public Document HandleRequest(int iRequest) {
		System.out.println("Trying AddFooter");
		Document doc = new Document(4, "AddFooter");
		doc.SetSuccess(doc.GetData() == iRequest);
		return doc;
	}
}

class DocumentFormat {
	private static IFormat[] m_aySolution = {
		new EnlargeFont(),
		new ChangeColor(),
		new AddHeader(),
		new AddFooter()
	};

	public static Document Solve(int iRequest) {
		for (int i = 0; i < m_aySolution.length; i++) {
			Document doc = m_aySolution[i].HandleRequest(iRequest);
			if (doc.IsSuccess()) {
				return doc;
			}
		}

		throw new RuntimeException("Unsolevd: "+iRequest);
	}
}

public class Sample {
	public static void main(String[] args) {
		int iRequest = 3;
		System.out.println("Request 3 => "+DocumentFormat.Solve(iRequest).GetName());
	}
}
