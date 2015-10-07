テストケース作成ログ
===================
2015/09/16 kohei-y

## Logic and Bit Operations
+ Bitwise Operator
	- パラメータ
		* 演算子：ANDは共通
		* [Bitwise_Operator_nomask.slx]ビットマスク：なし  
		* [Bitwise_Operator_mask.slx]ビットマスク：あり。マスクは bin2dec('11011001')  
	- 備考
		* 演算子には、他にもORとかNANDとか色々あるけど、大丈夫だろうと思いさしあたりANDのみを作成。
		また、NOTの時のみ、ビットマスクのチェックボックスは消える。
+ Combinatorial Logic
	- パラメータ
		* 真理値表 [0 0;0 1;0 1;1 0;0 1;1 0;1 0;1 1]
			+ 真理値表の行数が8なので、入力は要素数3のBooleanの配列に限定される。（それ以外を入力すると怒られる）。
+ Compare to Constant
	- パラメータ
		* 演算子：<=、定数値：3.0、出力型：Boolean
+ Compare to Zero
	- パラメータ
		* 演算子：<=、出力型：Boolean
+ Detect Change
	- パラメータ
		* [Detect_Change_SampleBase.slx]入力処理：チャンネルとしての列（サンプルベース）
		* [Detect_Change_FrameBase.slx]入力処理：チャンネルとしての列（フレームベース）
+ Logical Operator
	- パラメータ
		* 入力端子の数：3、演算子：AND
	- 備考
		* 演算子には、他にもORとかNANDとか色々あるけど、大丈夫だろうと思いさしあたりANDのみを作成。
		また、NOTの時のみ、入力のポート数は1。他は1以上の任意整数を指定可能。（テストもデルでは3にしてみた）
+ Shift Arithmetic
	- パラメータ
		* [Shift_Arithmetic_Dlg]：シフト量はダイアログで（静的に）決定。当モデルは8ビットシフト
		* [Shift_Arithmetic_Input]：シフト量は2番目の入力端子から決定。
	- 備考
		* 入力端子のか図が、DlgとInputで異なります。

## Signal Attributes
+ Data Type Conversion
	- パラメータ
		* 出力データ型：継承、整数丸めモード：負方向への丸め
	- 備考
		* Inportブロックのデータ型をdoubleに、Outportブロックのデータ型をint32に指定しています。
		Data Type Conversionは、Outportの端子の型を継承し、int32型のデータを吐くはずです。
		今回触れていないパラメータとして「固定小数点ツールによる変更に対して出力データ型の設定をロックする」や
		「整数オーバーフローで飽和」のチェックボックスなどがあり、設定によっては通るか怪しいかも？
+ IC
	- パラメータ
		* 初期値：100
	- 個人的な文句
		* 何でこのブロック、Initial Conditionって言わずにわざわざICって略すんだろう……？
+ Rate Transition
	- パラメータ
		* [Rate_Transition_Copy.slx]出力端子のサンプル時間：0.2、
		データ転送中の整合性を保証○、確定的にデータ転送を保証（最大遅延）○
		* [Rate_Transition_DbBuf.slx]出力端子のサンプル時間：0.2、
		データ転送中の整合性を保証○、確定的にデータ転送を保証（最大遅延）×
		Inportブロックのレートを0.3、Outportブロックのレートを0.2に指定。
		* [Rate_Transition_ZOH.slx]出力端子のサンプル時間：0.2
		データ転送中の整合性を保証○、確定的にデータ転送を保証（最大遅延）○
		Inportブロックのレートを0.1、Outportブロックのレートを0.2に指定。
	- 備考
		* Rate Transitioの実装が、入出力の情報によって「自動的に決定される」（我々は指定できず、
		設定の情報を下にMATLABが勝手に決める）。Copyはそのまま出力。DbBufは二重バッファで変換、
		ZOHはZero Order Holdで変換など。他にも何種類かあるんだけど、どういう設定をすると
		実装が変わるかさっぱりなのでここで断念。
+ Signal Conversion
	- パラメータ
		* [Signal_Conversion_Copy.slx]出力：信号のコピー
		* [Signal_Conversion_VBus.slx]出力：バーチャルバス
		* [Signal_Conversion_Bus.slx]出力：非バーチャルバス
	- 備考
		* バスまわりって何かちょっと怖いので一応。
+ Width
	- パラメータ
		* 出力データ型モード：Choose intrinsic data type、出力データ型：double
	- 備考
		* テストケースとして正しいのかちょっと不安

## Signal Routing
+ Bus Assignment
	- パラメータ
		* 割り当てられる信号：x
		* 代入値側につながっているConstantブロック：5
	- 備考
		* 入力ポートを2つ作って、そこから出る先にそれぞれx, yと名づけています。
		というか、拙作Bus CreatorのテストモデルにBus Assignmentをくっつけたモデルです。
+ Bus Creator
	- パラメータ
		* 入力端子からバス信号名を継承
	- 備考
		* 入力ポートを2つ作って、そこから出る先にそれぞれx, yと名づけています。
		* 実はCommomly Used Blockだったりするじゃないですかこれ……
+ Bus Selector
	- パラメータ
		* 選択された信号：x
	- 備考
		* 拙作Bus CreatorのテストモデルにBus Selectorをくっつけたモデルです。
		* 実はCommomly Used Blockだったりするじゃないですかこれ……
+ Data Store Memory
	- 作らないんでdsm_sampleを用いてください。正直言って、Memory/Read/Writeは切り離せないです。
+ Demux
	- 山本くん、よろしくお願いします。
+ From / Goto
	- パラメータ
		* タグの名前：A、タグの可視性：ローカル
	- 備考
		* 切り離しようがないので1モデルで。
+ Goto Tag Visivility
	- パラメータ
		* <Gotoブロック>タグの可視性：スコープ
	- 備考
		* 正直使い方がいまいち分かっていない
+ Merge
	- 池田くん作のif_action_subsystem.slxでテストしてください。同梱のモデルは、池田くんのモデルの
	名前だけMerge.slxにしています。
+ Multiport Switch
	- パラメータ
		* データ端子数：3、default ケースのデータ端子：最後のデータ端子、default ケースの診断：エラー
	- 備考
		* Reactis Notes *'Data port for default case' must be 'Last data port' and
		'Diagnostic for default case' must be 'Error'* に準拠
+ Mux
	- 山本くん、よろしくお願いします。
+ Selector
	- パラメータ
		* 入力の次元数：1、インデックス モード：1ベース
 
|                      | インデックス | 出力サイズ    |
|----------------------|:------------|---------------|
| インデックス ベクトル | [1 3]       | Indexから継承 |

+ Switch
	- 山本くん、よろしくお願いします。
+ Vector Concatenate
	- 山本くん、よろしくお願いします。

