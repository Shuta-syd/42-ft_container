# 42-ft_container
### What is STL Library?
	STLとは、動的配列や双方向リンクリスト、連想配列などといった基本的なデータ構造を、type-safeかつ最小コーディングで再利用するためのライブラリ。
	ライブラリとはいっても、ほとんどtemplateでできているので、ヘッダファイルをインクルードすればすぐ使えます。

### What is SFINAE?
	SFINAEとはSubstitution Falilure Is Not An Errorの略で、直訳すると「置き換え失敗はエラーではない」という意味
	あるテンプレートの展開において、置き換えに失敗した場合はそこでコンパイルエラーとするのではなく、対象から除外してコンパイルを継続する機能
	URL: https://izadori.net/cpp-templ-sfinae/

### Reference
	URL: 
		https://cpprefjp.github.io/
		https://en.cppreference.com/w/cpp
		https://cplusplus.com/reference/stl/
		https://nafuka.hatenablog.com/entry/2021/12/06/014200
		https://www.slideshare.net/HEXADRIVE/c-c98stlc11

## Git Guidelines
	- Keep it short (less than 100 characters total)
	- Specify what changes have been made([add],[fix],[rm],[update],[move],[rename],[improve])
	- Append the issue number to the prefix
	- Clearly state in the body why the change was made
	example) #X(what is the issue number) [add (what did you do change)] :[body (why did you change)]
