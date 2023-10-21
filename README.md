# MyWork
[SSD1322_OLED_library-master](https://github.com/wjklimek1/SSD1322_OLED_library) 오픈 소스를 활용한 OLED 국문/영문 출력 예제입니다.

# Discription
한글을 포함한 비트맵 폰트를 이용하여 문자를 출력하는 예제입니다. [SSD1322_OLED_library-master](https://github.com/wjklimek1/SSD1322_OLED_library)에서 제공하는 API library, GFX library를 기반으로 작성되었습니다.

미리 입력해둔 문구들이 순차적으로 반복되어 OLED 패널에 표시되는 동작을 수행하고, 국문/영문 및 기본적인 특수문자 등을 출력할 수 있습니다.

# Note
ST사의 SoC를 이용하여 OLED 모듈과 SPI를 통해 통신합니다. 이 모듈에서는 추가적으로 데이터와 명령 구분을 위한 D/C핀 설정이 필요합니다.
모듈에 따라 지원하는 SPI 모드 설정 등은 사용 환경에 맞추어야 하고, 이 모듈에서는 모드 3(CPOL = 1, CPHA = 1)을 사용했습니다.

## Preparation
본 예제를 통해 OLED 모듈을 동작시키기 위해서는 아래 구성이 준비되어야 합니다.
1. STM32F446xC/E MCU 준비.
2. IAR WorkBench IDE 또는 STM32CubeIDE. (여기서는 IAR WorkBench를 사용했습니다.)
3. IAR Compiler 또는 평가판.
4. MCU 메모리에 적합한 한글 비트맵 폰트.
([Creating a bitmap font for Korean/English](#creating-a-font) 참고)

## Example Result
• 영문 + 한글 조합 문자를 출력

<img src="https://github.com/Boseong-Boseong/myWork/assets/70252590/c904d552-83dd-4d47-96b7-d2a799a37c85"  width="600">
<img src="https://github.com/Boseong-Boseong/myWork/assets/70252590/6c64c33b-1fa1-439e-aa4b-f6d304326946"  width="600">
<img src="https://github.com/Boseong-Boseong/myWork/assets/70252590/77e2eb80-bd18-4a23-8aee-1c06bd50e1e3"  width="600">
<img src="https://github.com/Boseong-Boseong/myWork/assets/70252590/da72d65b-351c-4381-8a76-f211e3fb2881"  width="600">

## Creating a bitmap font for Korean/English
한글 폰트 제작은 Adafruit-GFX-Library-master 오픈 소스에서 제공하는 fontconvert를 사용했습니다.

### Preparation
[Adafruit-GFX-Library-master](https://github.com/adafruit/Adafruit-GFX-Library) 를 이용하여 한글 비트맵 폰트를 생성하기 위해서는 리눅스 환경에서 아래 구성이 준비되어야 합니다.
여기서는 Ubuntu를 이용했습니다.

1. [Adafruit-GFX-Library-master](https://github.com/adafruit/Adafruit-GFX-Library) 라이브러리 다운로드
2. ../Adafruit-GFX-Library-master/gfxfont.h 에서 12번째 줄 코드를 아래와 같이 수정
```
uint16_t bitmapOffset; -> uint32_t bitmapOffset; 
```
3. libfreetype6-dev 개발 패키지 설치
```
sudo apt-get install libfreetype6-dev 
```
4. ../Adafruit-GFX-Library-master/fontconvert 경로에서 빌드
```
make 
```

### Creating a font
원하는 .ttf 폰트를 ../Adafruit-GFX-Library-master/fontconvert 경로에 다운로드하고 아래 명령어를 실행합니다.

```
./my_font.ttf 16 44032 55203 > my_font.c
```
위 코드에서 16은 글씨 크기를, 44032(0xAC00)는 첫 글자 코드, 55203(0xD7A3)은 마지막 글자 코드를 의미하고, 0xAC000부터 0xD7A3까지의 폰트를 생성하는 명령어입니다. 여기서는 가(0xAC00)부터 힣(0xD7A3)을 생성합니다.

```
./fontconvert my_font.ttf 16 > my_font.c
```
44032 55203와 같은 범위를 따로 지정하지 않는 경우, 기본값으로 영문 및 기본 특수문자가 생성됩니다. (0x20 ~ 0x7E 범위로 생성)
