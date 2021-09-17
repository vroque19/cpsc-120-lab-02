#!/usr/bin/env python3
#
# Copyright 2021 Michael Shafae
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
# 
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
""" Check student's submission; requires the main file and the
    template file from the original repository. """
# pexpect documentation
#  https://pexpect.readthedocs.io/en/stable/index.html
import logging
import pexpect
from srcutilities import solution_check_make


def run_p1(binary):
    """ Run part-1 """
    status = True
    values = (
        ('f', '35', 'm', '164', '57', '164', '57', '1259',),
        ('m', '30', 'u', '70', '174', '177.8', '78.909', '1755.34',),
        ('f', '30', 'm', '173.4', '54.25', '173.4', '54.25', '1315.25',),
        )
    for index, val in enumerate(values):
        logging.info('Test %d - %s %s', index + 1, val[:4], val[-1])
        status = status and  _run(binary, val)
        if not status:
            logging.error("Did not receive expected response. Halting test.")
            break
    return status


def _run(binary, values):
    """ This is the test for the BMR program given the inputs from run_p1 """
    status = False
    proc = pexpect.spawn(binary, timeout=1)
    #proc.logfile = sys.stdout.buffer
    try:
        proc.expect(r'(?i)\s*Please\s+enter\s+\'m\'\s+for\s+male\s+or\s+\'f\'\s+for\s+female:\s*')
    except (pexpect.exceptions.TIMEOUT, pexpect.exceptions.EOF) as exception:
        logging.error('Could not find expected output.')
        logging.debug("%s", str(exception))
        logging.debug(str(proc))
        return status

    proc.sendline(values[0])

    try:
        proc.expect(r'(?i)\s*Please\s+enter\s+the\s+subject\'s\s+age\s+in\s+years\s+\(no\s+decimal\s+point\s+please\):\s*')
    except (pexpect.exceptions.TIMEOUT, pexpect.exceptions.EOF) as exception:
        logging.error('Could not find expected output.')
        logging.debug("%s", str(exception))
        logging.debug(str(proc))
        return status

    proc.sendline(values[1])

    try:
        proc.expect(r'(?i)\s*Enter\s+\'m\'\s+for\s+metric\s+and\s+\'u\'\s+for\s+U.S.:\s*')
    except (pexpect.exceptions.TIMEOUT, pexpect.exceptions.EOF) as exception:
        logging.error('Could not find expected output.')
        logging.debug("%s", str(exception))
        logging.debug(str(proc))
        return status

    proc.sendline(values[2])

    try:
        proc.expect(r'(?i)\s*Please\s+enter\s+height\s+in\s+\w+,\s+decimal\s+points\s+are\s+OK:\s+')
    except (pexpect.exceptions.TIMEOUT, pexpect.exceptions.EOF) as exception:
        logging.error('Could not find expected output.')
        logging.debug("%s", str(exception))
        logging.debug(str(proc))
        return status

    proc.sendline(values[3])

    try:
        proc.expect(r'(?i)\s*Please\s+enter\s+weight\s+in\s+\w+,\s+decimal\s+points\s+are\s+OK:\s+')
    except (pexpect.exceptions.TIMEOUT, pexpect.exceptions.EOF) as exception:
        logging.error('Could not find expected output.')
        logging.debug("%s", str(exception))
        logging.debug(str(proc))
        return status

    proc.sendline(values[4])

    try:
        proc.expect(r'(?i)\s*Given\s+the\s+details\s+of\s+the\s+\w+\s+subject\s+of\s+{}\s+years\s+of\s+age,\s+with\s+a\s+height\s+of\s+{}+\s+cm\s+and\s+a\s+weight\s+of\s+{}\s+kg...\s+\w+\s+has\s+a\s+BMR\s+of\s+{}\s+kcal\s+per\s+day.\s*'.format(values[1], values[5], values[6], values[7]))
    except (pexpect.exceptions.TIMEOUT, pexpect.exceptions.EOF) as exception:
        logging.error('Could not find expected output.')
        logging.debug("%s", str(exception))
        logging.debug(str(proc))
        return status

    proc.expect(pexpect.EOF)
    proc.close()
    if proc.exitstatus == 0:
        status = True
    return status


if __name__ == '__main__':
    solution_check_make(run=run_p1)
