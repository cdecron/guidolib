/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class guidoengine_guido */

#ifndef _Included_guidoengine_guido
#define _Included_guidoengine_guido
#ifdef __cplusplus
extern "C" {
#endif
#undef guidoengine_guido_kNoBB
#define guidoengine_guido_kNoBB 0L
#undef guidoengine_guido_kPageBB
#define guidoengine_guido_kPageBB 1L
#undef guidoengine_guido_kSystemsBB
#define guidoengine_guido_kSystemsBB 2L
#undef guidoengine_guido_kSystemsSliceBB
#define guidoengine_guido_kSystemsSliceBB 4L
#undef guidoengine_guido_kStavesBB
#define guidoengine_guido_kStavesBB 8L
#undef guidoengine_guido_kMeasureBB
#define guidoengine_guido_kMeasureBB 16L
#undef guidoengine_guido_kEventsBB
#define guidoengine_guido_kEventsBB 32L
#undef guidoengine_guido_guidoNoErr
#define guidoengine_guido_guidoNoErr 0L
#undef guidoengine_guido_guidoErrParse
#define guidoengine_guido_guidoErrParse -1L
#undef guidoengine_guido_guidoErrMemory
#define guidoengine_guido_guidoErrMemory -2L
#undef guidoengine_guido_guidoErrFileAccess
#define guidoengine_guido_guidoErrFileAccess -3L
#undef guidoengine_guido_guidoErrUserCancel
#define guidoengine_guido_guidoErrUserCancel -4L
#undef guidoengine_guido_guidoErrNoMusicFont
#define guidoengine_guido_guidoErrNoMusicFont -5L
#undef guidoengine_guido_guidoErrNoTextFont
#define guidoengine_guido_guidoErrNoTextFont -6L
#undef guidoengine_guido_guidoErrBadParameter
#define guidoengine_guido_guidoErrBadParameter -7L
#undef guidoengine_guido_guidoErrInvalidHandle
#define guidoengine_guido_guidoErrInvalidHandle -8L
#undef guidoengine_guido_guidoErrNotInitialized
#define guidoengine_guido_guidoErrNotInitialized -9L
#undef guidoengine_guido_guidoErrActionFailed
#define guidoengine_guido_guidoErrActionFailed -10L
/*
 * Class:     guidoengine_guido
 * Method:    Init
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_guidoengine_guido_Init
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     guidoengine_guido
 * Method:    xml2gmn
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_guidoengine_guido_xml2gmn__
  (JNIEnv *, jclass);

/*
 * Class:     guidoengine_guido
 * Method:    musicxmlversion
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_guidoengine_guido_musicxmlversion
  (JNIEnv *, jclass);

/*
 * Class:     guidoengine_guido
 * Method:    musicxml2guidoversion
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_guidoengine_guido_musicxml2guidoversion
  (JNIEnv *, jclass);

/*
 * Class:     guidoengine_guido
 * Method:    xml2gmn
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_guidoengine_guido_xml2gmn__Ljava_lang_String_2
  (JNIEnv *, jclass, jstring);

/*
 * Class:     guidoengine_guido
 * Method:    GetErrorString
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_guidoengine_guido_GetErrorString
  (JNIEnv *, jclass, jint);

/*
 * Class:     guidoengine_guido
 * Method:    GetParseErrorLine
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_guidoengine_guido_GetParseErrorLine
  (JNIEnv *, jclass);

/*
 * Class:     guidoengine_guido
 * Method:    Unit2CM
 * Signature: (F)F
 */
JNIEXPORT jfloat JNICALL Java_guidoengine_guido_Unit2CM
  (JNIEnv *, jclass, jfloat);

/*
 * Class:     guidoengine_guido
 * Method:    CM2Unit
 * Signature: (F)F
 */
JNIEXPORT jfloat JNICALL Java_guidoengine_guido_CM2Unit
  (JNIEnv *, jclass, jfloat);

/*
 * Class:     guidoengine_guido
 * Method:    Unit2Inches
 * Signature: (F)F
 */
JNIEXPORT jfloat JNICALL Java_guidoengine_guido_Unit2Inches
  (JNIEnv *, jclass, jfloat);

/*
 * Class:     guidoengine_guido
 * Method:    Inches2Unit
 * Signature: (F)F
 */
JNIEXPORT jfloat JNICALL Java_guidoengine_guido_Inches2Unit
  (JNIEnv *, jclass, jfloat);

/*
 * Class:     guidoengine_guido
 * Method:    GetVersion
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_guidoengine_guido_GetVersion
  (JNIEnv *, jclass);

/*
 * Class:     guidoengine_guido
 * Method:    GetJNIVersion
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_guidoengine_guido_GetJNIVersion
  (JNIEnv *, jclass);

/*
 * Class:     guidoengine_guido
 * Method:    CheckVersionNums
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_guidoengine_guido_CheckVersionNums
  (JNIEnv *, jclass, jint, jint, jint);

/*
 * Class:     guidoengine_guido
 * Method:    GetLineSpace
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_guidoengine_guido_GetLineSpace
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif