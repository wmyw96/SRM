### 250pt
#### �㷨����
̰�ļ��ɡ�
#### ��ע
+0
#### tags
̰��

### 500pt
#### �㷨����
���ִ𰸣����ᳬ��150������150��ֱ�����-1����֮���ò��ֺ�����300^2��check
#### ��ע
+0
#### tags
���ִ𰸣����ֺ��Ż�

### 1000pt
#### ��Ŀ����
����N������x_i�����ڵ�i������������ֵ����Ҫ��[low_i, up_i]֮�䣬������ʵ�����������
\sum_{i=1}^{N}{\sum_{j=1}^{i-1}{g(i,j) * x_i*x_j}}
g(x,y)�Ǹ����Ĳ���ֻ������0����1��
#### �㷨����
���ǰ���N�������ֳ�3�ࣺȡ��Сֵ��ȡ���ֵ��ȡ�м䡣
���ǿ���֤�������Ҫʹ�ô����ţ�ȡ�м�ļ���S��һ������֮���g��1��
Ϊʲô�أ����������ڵ�u,v����val(i)��ʾx_i��sum(u)��ʾ��u��gֵΪ1����x��val(x)֮�ͣ�������sum(u)>=sum(v)����ô��u���һ��㣬��v��Сһ��㣬�𰸻���š�
Ȼ�����Ǽ������ǣ���a_i��ʾȡ�м�Ľڵ�i��\sum{j,val(j)ȡ��ֵ}{val(j)}��
Ҫ��Ĵ𰸾���ȡ�м�ĺ�ȡ��ֵ�ĺͣ�����ȡ�м�ĺ�ȡ�м�ĺ͡�
��M��ʾmaxS-�Ѿ�ȷ����i�ĺ͡�
��ô��Ҫ��ĵ�ʽ�Ӿ���
\sum_{i in S}{x_i*(a_i+(M-x_i)/2)}
���ӵ������������Ҫ���\sum_{i in S}{x_i*(a_i-x_i/2)}
���ǿ��ǵ�����������һ�����κ�������x_i=a_i��ʱ��ȡ���ֵ��
����ÿ���������½�������һ���ġ�
��ô����һ���������еĶ������������ֵ��ʾ��x�ľ���һ�������������Ϊd��
d=(\sum_{i in S}{a_i}-M)/|S|��
���x_i=a_i-d
�����ִ�����һ�����⣺������ڷ�Χ����ô�죿
�ܼ򵥣���ȥ���ɣ�
Ϊʲô����Ϊ��������Ļ��������Ӧ��ȡ��ֵ����
#### ��ע
+0
#### tags
������ֵ������