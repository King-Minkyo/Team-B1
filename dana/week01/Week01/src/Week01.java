import java.util.*;

public class Week01 {

	public static void main(String[] args) {
		
		System.out.println("��ȣ�� �Է��ϼ���.(���� 100,000 ����)");
		Scanner s = new Scanner(System.in);
		
		String g = s.next();
		
		char[] gg = g.toCharArray();
		
		int a=0;
		int b=0;
		
		for(int i = 0;i<g.length();i++) {
			if(gg[i] == '(') {
				a++;
			}else if(gg[i] == ')') {
				b++;
			}
		}
		
		
		System.out.println(a+"  "+b);
		
	}

}
