### 250pt
#### �㷨����
ģ�⼴�ɡ�
#### ��ע
+0
#### tags
ģ��

### 500pt
����ļ��㼸��...

### 1000pt
#### ��Ŀ����
����һ��N���ڵ������������Ҫ��N���ڵ����±�ţ�ʹ�ö��ڵ㼯{1,2,..k},{2,3..k+1},..{n-k+1.n-k+2,..,n}��������������ϵĵ��������ĵ�������k��
#### �㷨����
����Ĺؼ�������yy��������״��
����2k<=n����ô��һ�����м�һ��������Ȼ�����߶����Ŵ�СΪK������������ͼ��
-------------------------------------------------
|  [STA] - (k+1) - (k+2) - ... - (n-k) - [STB]  |
-------------------------------------------------   Image1

STA��ôȾɫ��ʵ���Ͼ������еĶ��Ӷ�Ҫ�ȸ���С����Ⱦɫ�ķ�����������һ�����������dp��������f[x][p]��ʾx�ڵ㸸��Ϊp��Ⱦɫ�ܷ�������
��ȻSTB������STA��
Ȼ������Ϳ������ˡ�
��2k>n��ô�죿
���ǿ�����ʵ��״�������ģ��м���һ���ܴ����ͨ����2k-n����ͨ���һЩ�ڵ�����һ��������Ҫô����[1,v]��ģ�Ҫô����[n-v+1,n]��ģ���ô�����ǿ��������������һ����ά�����Ϳ����ˡ�
���ǣ�ע�⵽����������ǣ���iΪ��ͨ���е�root������Ҫ��(2k-n)!����������Ҳ�Ǵ��ģ�ͬһ����ͨ��ᱻ���㵽(2k-n)�Σ���ȥ�Ϳ����ˡ�
#### ��ע
+0
(wt)
����ע�����㣺
dp�е�ʱ��Ҫ��������״̬
�ݳ�Ҳ�����ó���������������ȷ����ʱ��
#### tags
����dp�����ۣ����ϱ������ݳ�