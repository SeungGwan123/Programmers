import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] starts = new int[n];
        int[] ends = new int[n];

        // 입력: 강의 번호는 사용하지 않으므로 읽고 버립니다.
        for (int i = 0; i < n; i++) {
            sc.nextInt(); // 강의 번호
            starts[i] = sc.nextInt();
            ends[i] = sc.nextInt();
        }

        // 시작 시간과 종료 시간을 각각 정렬
        Arrays.sort(starts);
        Arrays.sort(ends);

        int rooms = 0;      // 현재 진행 중인 강의 수 (= 사용 중인 강의실 수)
        int maxRooms = 0;   // 필요한 최대 강의실 수
        int i = 0, j = 0;

        // 두 배열을 동시에 순회하면서 강의실 필요 개수 계산
        while (i < n) {
            // 다음 강의 시작시간이 가장 빠른 종료시간보다 작으면 새로운 강의실 필요
            if (starts[i] < ends[j]) {
                rooms++;
                maxRooms = Math.max(maxRooms, rooms);
                i++;
            } else {
                // 현재 강의가 끝났으므로 강의실 하나 해제
                rooms--;
                j++;
            }
        }

        System.out.println(maxRooms);
    }
}
