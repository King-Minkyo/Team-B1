import java.util.*;

public class Week03_1 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int[] pasta = new int[3];
		
		int[] juice = new int[2];
		
		System.out.println("모든 음식의 가격은 100원 이상, 2000원 이하의 가격을 입력해주세요.");
		System.out.printf("1번째 파스타 가격: ");
		pasta[0] = sc.nextInt();
		
		System.out.print("2번째 파스타 가격: ");
		pasta[1] = sc.nextInt();
		
		System.out.print("3번째 파스타 가격: ");
		pasta[2] = sc.nextInt();
		
		System.out.print("1번째 생과일주스 가격: ");
		juice[0] = sc.nextInt();
		
		System.out.print("2번째 생과일주스 가격: ");
		juice[1] = sc.nextInt();
		
		
		double[] tot = new double[6];
		
		tot[0] = (pasta[0] + juice[0])*(1.1);
		tot[0] = Math.floor(tot[0]/10.0);
		
		tot[1] = (pasta[0] + juice[1])*(1.1);
		tot[1] = Math.floor(tot[1]/10.0);
		
		tot[2] = (pasta[1] + juice[0])*(1.1);
		tot[2] = Math.floor(tot[2]/10.0);
		
		tot[3] = (pasta[1] + juice[1])*(1.1);
		tot[3] = Math.floor(tot[3]/10.0);
		
		tot[4] = (pasta[2] + juice[0])*(1.1);
		tot[4] = Math.floor(tot[4]/10.0);
		
		tot[5] = (pasta[2] + juice[1])*(1.1);
		tot[5] = Math.floor(tot[5]/10.0);
		
		
		double min = tot[0];
		
		for(int i=0;i<6;i++) {
			if(min>tot[i]) {
				min=tot[i];
			}
		}
		
		System.out.println("최소 세트 금액: "+min);
		

	}

}
