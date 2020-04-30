import java.io.*;
import java.net.URI;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FSDataInputStream;
import org.apache.hadoop.fs.FileStatus;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;

public class MaxGrade {
    public static void main(String[] args) {
        String str = null;
        int cnt = 0;
        int Max_Grade[] = new int[100];
        int c[] = {0, 0, 0, 0, 0, 0, 0, 0, 0 , 0};
        Configuration conf = new Configuration();
        String pathString=new String("hdfs://master:9000/inputFile/1805121成绩.txt");//the goal file path
        String pathString1=new String("hdfs://master:9000/inputFile/1805122成绩.txt");
        URI pathURI = URI.create(pathString);
        try {
            FileSystem fs = FileSystem.get(pathURI, conf);
            Path file = new Path(pathString);
            fs.copyFromLocalFile(new Path("/root/inputfile"), file);
            FileStatus status[] = fs.listStatus(file);
            for (FileStatus fil : status) {
                System.out.println(fil.getPath());
                FSDataInputStream in = fs.open(fil.getPath());
                BufferedReader br = new BufferedReader(new InputStreamReader(in));
                //读取数据
                while ((str = br.readLine()) != null) {
                    String st[] = str.split(",");
                    if (cnt == 0) {
                        for (int i = 2; i < st.length; i++)
                            System.out.print(st[i] + "  ");
                        System.out.println();
                        cnt++;
                        continue;
                    }
                    for (int i = 2; i < st.length; i++)
                        Max_Grade[i - 2] = Integer.parseInt(st[i]);
                    for (int i = 0; i < Max_Grade.length; i++) // 求最大值
                    {
                        if (c[i] > Max_Grade[i])
                            Max_Grade[i] = c[i];
                    }
                }
                cnt = 0;
            }
            System.out.println("各科最高分依次是：");
            for (int i = 0; i < Max_Grade.length; i++)
                System.out.print(Max_Grade[i] + "  ");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
