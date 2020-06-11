/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#include <string>
#include <vector>

namespace bsnesMt::app {

using std::string, std::vector;

static const char* title        = "bsnes-mt";
static const char* version      = "1.0";
static const char* urlEn        = "http://tanalin.com/en/projects/bsnes-mt/";
static const char* urlRu        = "http://tanalin.com/projects/bsnes-mt/";
static const char* articleUrlEn = "http://tanalin.com/en/articles/integer-scaling/";
static const char* articleUrlRu = "http://tanalin.com/articles/integer-scaling/";

static const string authorEn      = "Marat Tanalin";
static const string authorRu      = u8"Марат Таналин";
static const string articleLinkEn = string("<a href=\"") + articleUrlEn + "\">" + articleUrlEn + "</a>";
static const string articleLinkRu = string("<a href=\"") + articleUrlRu + "\">" + articleUrlRu + "</a>";
static const string linkEn        = string("<a href=\"") + urlEn + "\">" + urlEn + "</a>";
static const string linkRu        = string("<a href=\"") + urlRu + "\">" + urlRu + "</a>";

static const string infoEn = u8"Improved version of bsnes:\n\n"
                             u8"• " + string("<a href=\"") + articleUrlEn + "\">" +
                             u8"pixel-perfect integer-ratio scaling" + "</a>;\n" +
                             u8"• precise 4:3 in the “Center” and “Scale” modes;\n"
                             u8"• compressed PNG screenshots, and more.\n\n"
                             u8"© 2020 " + authorEn + "\n" + linkEn;

static const string infoRu = u8"Улучшенная версия bsnes:\n\n"
                             u8"• " + string("<a href=\"") + articleUrlRu + "\">" +
                             u8"целочисленное масштабирование без размытия" + "</a>;\n" +
                             u8"• точное 4:3 в режимах «Center» и «Scale»;\n"
                             u8"• PNG-скриншоты со сжатием, и проч.\n\n"
                             u8"© 2020 " + authorRu + "\n" + linkRu;

static const string windowTitle = string(title) + ' ' + version;

static const vector<unsigned char> pngInfo = {
	0, 0, 0, 60, 116, 69, 88, 116, 83, 111, 102, 116, 119, 97, 114, 101, 0, 98,
	115, 110, 101, 115, 45, 109, 116, 32, 124, 32, 104, 116, 116, 112, 58, 47,
	47, 116, 97, 110, 97, 108, 105, 110, 46, 99, 111, 109, 47, 101, 110, 47,
	112, 114, 111, 106, 101, 99, 116, 115, 47, 98, 115, 110, 101, 115, 45, 109,
	116, 47, 136, 188, 137, 5
};

} // namespace bsnesMt::app