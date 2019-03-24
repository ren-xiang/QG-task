# QG训练营移动组第一周周记：2019年3月23日

## 生活随记
今天好像没什么效率，可能周末放假叭，进度有点慢，而且学了好久没什么进展，有点烦躁。
今天主要干了一下几个任务叭。
一是写大组那个作业，链表的增删查改，那些作业，只写了一个linklist那个里面的作业，感觉效率是很低了，链表的东西好多都忘了，看完了基础知识，又去上网看了些题目才勉强回忆起那些知识。
看链表看久了又没什么进展，就又去看了下java，今天算是看了点东西，java8 增强的工具类：Arryas，java提供了Arrays类里面包含的一些static修饰的方法可以直接操作数组。给了一些
该类的方法，我学习了一下并试着敲了个demo：

import java.util.Arrays;
public class Num2Rmb {
    private String[] hanArr = { "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖" };
    private String[] unitArr = { "十", "百", "千" };

    /**
     * 把一个浮点数分解成整数部分和小数部分字符串
     * 
     * @param num 需要被分解的浮点数
     * @return 分解出来的整数部分和小数部分。第一个数组元素是整数部分，第二个数组元素是小数部分。
     */
    private String[] divide(double num) {
        // 将一个浮点数强制类型转换为Long型，即得到他的整数部分
        long zheng = (long) num;
        // 浮点数-整数=小数，（取整）小数*100 得到2位小数
        long xiao = Math.round((num - zheng) * 100);
        /** 下面用了2种方法把整数转换为字符串 */
        return new String[] { zheng + "", String.valueOf(xiao) };
    }

    /**
     * 四位数字字符串->汉字字符串
     * @param numStr 需要被转的四位的数字字符串
     * @return 四位的数字字符串被转换成汉字字符串
     */
    private String toHanStr(String numStr)
    {
        String result = "";
        int numLen = numStr.length();
        // 依次遍历数字字符串的每一位数字
        int numLen2 = numLen;
		for (int i = 0; i < numLen; i++) {
            /**
             char->int  ASCII差48
             char-48->int eg:'4'->4
             */
            int num = numStr.charAt(i) - 48;
            // if it wasn't the last number&& number!=0; 需要添加单位（千，白，十）
            if (i != numLen2 - 1 && num != 0)
                result += hanArr[num] + unitArr[numLen - 2 - i];
            else
                result += hanArr[num];
        }
        return result;
    }

    public static void main(String[] args) {
        Num2Rmb nr = new Num2Rmb();
        // 测试把一个浮点数分解成整数部分和小数部分
        System.out.println(Arrays.toString (nr.divide(236711125.123)));
        // 测试把一个四位数的数字字符串变成汉字字符串
        System.out.println(nr.toHanStr("6109"));
    }
}


同时今天也学习了一些面向对象的内容，大部分都是定义，希望明天能有所效率，更加进步




## 今日总结
总体来说，今天还是进步的，有学习到东西的，今天晚上的时候还和舍友打了几把LOL释放压力。希望明天能进步更大些。


## 存在问题
效率有点低，情绪有点不稳定，可能需要好好休息一下，释放压力调节一下。


## 明天规划
1、写完QG作业
2、学习面向对象
3、完成学校要求作业