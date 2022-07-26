import java.util.*;

public class Week04_1 {

	public static ArrayList<ArrayList<Integer>> map = new ArrayList<ArrayList<Integer>>();
	
	static int result = 0;
	
	static int[] node;
	
	public static void DFS(int num, int sheep, int wolf, boolean[] list) {
		
		if(node[num] == 0){
			sheep++;
		}
		else if(node[num] == 1) {
			wolf++;
		}
		
		if(wolf>=sheep) {
			return;
		}
		
		boolean[] newList = list.clone();
		newList[num] = true;
		
		result = Math.max(result, sheep);
		
		for(int i=0;i<newList.length;i++) {
			
			if(newList[i] == true) {
				
				for(int j=0;j<map.get(i).size();j++) {
					
					int temp = map.get(i).get(j);
					
					if(newList[temp]==false) {
						
						DFS(temp, sheep, wolf, newList);
					}
				}
			}
		}
	}
	
	
	public static void main(String[] args) {
		
	
	}

}
