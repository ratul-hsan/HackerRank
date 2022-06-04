import java.util.Map;
import java.util.HashMap;

public class MakingAnagrams {
	public static String problemUrl = "https://www.hackerrank.com/challenges/making-anagrams";
	
	public static void debugMap(Map map) {
		System.out.println("===== Debugging Map =====");
		for (Map.Entry entry : map.entrySet())
			System.out.println(entry.getKey() + " " + entry.getValue());
		System.out.println("========================");
	}
	
	public static void debugStrings(String s3, String s4) {
		System.out.println("s3 = " + s3);
		System.out.println("s4 = " + s4);
	}
	
	public static int makingAnagrams(String s1, String s2) {
		int totalDeletions = 0;
		// The short string or the first string parameter will be kept in s3
		String s3 = s1.length() <= s2.length() ? s1 : s2;
		// The large string or thr second string paramtere will be kept in s4
		String s4 = s2.length() >= s1.length() ? s2 : s1;
		Map<Character, Integer> map = new HashMap<Character,  Integer>();
		debugStrings(s3, s4);
		for (int i = 0; i < s3.length(); i++) {
			Integer value = map.get(s3.charAt(i));
			if (value != null)
				map.put(s3.charAt(i), value + 1);
			else
				map.put(s3.charAt(i), 1);
		}
		debugMap(map);
		for (int i = 0; i < s4.length(); i++) {
			Integer value = map.get(s4.charAt(i));
			if (value != null && value != 0)
				map.put(s4.charAt(i), value - 1);
			else
				totalDeletions++;
		}
		for (Map.Entry<Character, Integer> entry : map.entrySet())
			totalDeletions += entry.getValue();
		return totalDeletions;
	}
	
	public static void main(String[] args) {
		System.out.println(makingAnagrams("cde", "abc"));
	}
}
