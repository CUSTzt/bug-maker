
import org.apache.hadoop.io.Writable;

import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;

public class WebLogBean implements Writable{

    private String IP;// 记录客户端的ip地址
    private String time;// 记录访问时间与时区
    private String url;// 记录请求的url与http协议
    private String source;// 用来记录从那个页面链接访问过来的
    private String browser;// 记录客户浏览器的相关信息

    public void set(String remote_addr, String remote_user, String time_local, String request, String status, String body_bytes_sent, String http_referer, String http_user_agent) {
        this.IP = remote_addr;
        this.time = time_local;
        this.url = request;
        this.source = http_referer;
        this.browser = http_user_agent;
    }
    public void setIP(String IP) {
        this.IP = IP;
    }
    public void setTime(String time) {
        this.time = time;
    }
    public void setURL(String url) {
        this.url = url;
    }
    public void setSource(String source) {
        this.source = source;
    }
    public void setExplorer(String browser) {
        this.browser = browser;
    }
    public String getIP() {
        return IP;
    }
    public String getTime() {
        return time;
    }
    public String getURL() {
        return url;
    }
    public String getSource() {
        return source;
    }
    public String getExplorer() {
        return browser;
    }
    //重新整合数据，将数据以IP，时间，URL，访客来源，浏览器信息的格式排列
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(" ").append(this.getIP());
        sb.append(" ").append(this.getTime());
        sb.append(" ").append(this.getURL());
        sb.append(" ").append(this.getSource());
        sb.append(" ").append(this.getExplorer());
        return sb.toString();
    }
    //重新定义WebLogBean的序列化方式，减轻无用信息的负载
    public void write(DataOutput out) throws IOException {
        out.writeUTF(null==IP?"":IP);
        out.writeUTF(null==time?"":time);
        out.writeUTF(null==url?"":url);
        out.writeUTF(null==source?"":source);
        out.writeUTF(null==browser?"":browser);
    }
    public void readFields(DataInput in) throws IOException {
        this.IP = in.readUTF();
        this.time = in.readUTF();
        this.url = in.readUTF();
        this.source = in.readUTF();
        this.browser = in.readUTF();
    }
}

